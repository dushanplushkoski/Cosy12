/* 
 * Copyright 2012-2024 The MathWorks, Inc.
 *
 * File: rt_main.cpp
 *
 * Abstract:
 *
 *   A real-time main that runs generated Simulink Coder code under most 
 *   operating systems.  Based on the definition of MULTITASKING, a single-task 
 *   or multitask step function is employed.
 *
 *   This file is a useful starting point for creating a custom main when 
 *   targeting a custom floating point processor or integer micro-controller.
 *
 *   Alternatively for ERT targets, you can generate a sample ert_main.cpp file 
 *   with the generated code by selecting the "Generate an example main program"
 *   option.  In this case, ert_main.cpp is precisely customized to the
 *   model requirements.  
 *
 * Required Defines:
 *
 *   MODEL - Model name
 *   NUMST - Number of sample times
 *
 */

/*==================*
 * Required defines *
 *==================*/

#ifndef MODEL
# error Must specify a model name.  Define MODEL=name.
#else
/* create generic macros that work with any model */
# define EXPAND_CONCAT(name1,name2) name1 ## name2
# define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
# define MODEL_INITIALIZE CONCAT(MODEL,_initialize)
# define MODEL_STEP       CONCAT(MODEL,_step)
# define MODEL_TERMINATE  CONCAT(MODEL,_terminate)
# define RT_MDL           CONCAT(MODEL,_M)
#endif

#ifndef NUMST
# error Must specify the number of sample times.  Define NUMST=number.
#endif

#if CLASSIC_INTERFACE == 1
# error "Classic call interface is not supported by rt_main.cpp."
#endif

#if ONESTEPFCN==0
#error Separate output and update functions are not supported by rt_main.cpp. \
You must update rt_main.cpp  to suit your application needs, or select \
the 'Single output/update function' option.
#endif

#if TERMFCN==0
#error The terminate function is required by rt_main.cpp. \
Select model configuration parameter 'Terminate function required' \
or 'Generate an example main program' or modify rt_main.cpp to \
meet your application requirements.
#endif

#if MULTI_INSTANCE_CODE==1
#error The static version of rt_main.cpp does not support reusable \
code generation.  Either deselect ERT option 'Generate reusable code', \
select option 'Generate an example main program', or modify rt_main.cpp for \
your application needs.
#endif

#ifndef SAVEFILE
# define MATFILE2(file) #file ".mat"
# define MATFILE1(file) MATFILE2(file)
# define MATFILE MATFILE1(MODEL)
#else
# define QUOTE1(name) #name
# define QUOTE(name) QUOTE1(name)    /* need to expand name    */
# define MATFILE QUOTE(SAVEFILE)
#endif

/*==========*
 /*==========*
 * Includes *
 *==========*/

#include "rtwtypes.h"
#if !defined(INTEGER_CODE) || INTEGER_CODE == 0
# include <stdio.h>    /* optional for printf */
#else
#ifdef __cplusplus
extern "C" {
#endif
  extern int printf(const char *, ...); 
  extern int fflush(void *);
#ifdef __cplusplus
}
#endif
#endif
#include <string.h>  /* optional for strcmp */
#include "rtmodel.h" /* optional for automated builds */

#include "rt_logging.h"
#ifdef UseMMIDataLogging
#include "rt_logging_mmi.h"
#endif

#include "ext_work.h"
#include <iostream>  // For std::cin and std::cout
/* Add your custom functions here */
void promptUserInputs(ExtU_Cosy12_Model4_T &inputs) {
    std::cout << "Enter value for In1: ";
    std::cin >> inputs.Inport1;

    std::cout << "Enter value for In2: ";
    std::cin >> inputs.Inport2;

    std::cout << "Enter value for In3: ";
    std::cin >> inputs.Inport3;

    std::cout << "Enter value for In4: ";
    std::cin >> inputs.Inport4;

    std::cout << "Enter value for In5: ";
    std::cin >> inputs.Inport5;

    std::cout << "Enter value for In6: ";
    std::cin >> inputs.Inport6;

  
}

void displayOutputs(const ExtY_Cosy12_Model4_T &outputs) {
    std::cout << "\nOutputs:\n";
    std::cout << "OUTPUT1: " << outputs.OUTPUT1 << "\n";
    std::cout << "OUTPUT2: " << outputs.OUTPUT2 << "\n";
    std::cout << "OUTPUT3: " << outputs.OUTPUT3 << "\n";
    std::cout << "OUTPUT4: " << outputs.OUTPUT4 << "\n";
    std::cout << "OUTPUT5: " << outputs.OUTPUT5 << "\n";
    std::cout << "OUTPUT6: " << outputs.OUTPUT6 << "\n";
    std::cout << "OUTPUT7: " << outputs.OUTPUT7 << "\n";
    std::cout << "OUTPUT8: " << outputs.OUTPUT8 << "\n";
    std::cout << "OUTPUT9: " << outputs.OUTPUT9 << "\n";
    std::cout << "OUTPUT10: " << outputs.OUTPUT10 << "\n";
    std::cout << "OUTPUT11: " << outputs.OUTPUT11 << "\n";
    std::cout << "OUTPUT12: " << outputs.OUTPUT12 << "\n";
    std::cout << "OUTPUT13: " << outputs.OUTPUT13 << "\n";
    std::cout << "OUTPUT14: " << outputs.OUTPUT14 << "\n";
    std::cout << "OUTPUT15: " << outputs.OUTPUT15 << "\n";
}
/*========================* 
 * Setup for multitasking * 
 *========================*/

/* 
 * Let MT be synonym for MULTITASKING (to shorten command line for DOS) 
 */
#if defined(MT)
# if MT == 0
# undef MT
# else
# define MULTITASKING 1
# endif
#endif

#if defined(MULTITASKING) /* multitask */
#if defined(TID01EQ) && TID01EQ == 1
#define FIRST_TID 1
#else 
#define FIRST_TID 0
#endif
#endif


/*==================================*
 * Global data local to this module *
 *==================================*/
#ifndef MULTITASKING
static uint_T OverrunFlags[1];    /* ISR overrun flags */
static uint_T eventFlags[1];      /* necessary for overlapping preemption */
#else
static uint_T OverrunFlags[NUMST];
static uint_T eventFlags[NUMST]; 
#endif

/*========================* 
 * Setup for RTM access macros* 
 *========================*/
 
#if defined(rtmGetStopRequested)  
    #define RTMStopRequested (rtmGetStopRequested(RT_MDL)) 
#else
    #define RTMStopRequested (RT_MDL->getStopRequested())
#endif


#if defined(rtmGetErrorStatus)  
    #define RTMGetErrorStatus (rtmGetErrorStatus(RT_MDL)) 
#else
    #define RTMGetErrorStatus (RT_MDL->getErrorStatus())
#endif

#if defined(rtmSetErrorStatus)  
    #define RTMSetErrorStatus(status) (rtmSetErrorStatus(RT_MDL,status)) 
#else
    #define RTMSetErrorStatus(status) (RT_MDL->setErrorStatus(status)) 
#endif

#if defined(rtmStepTask)  
    #define RTMStepTask(i) (rtmStepTask(RT_MDL,i)) 
#else
    #define RTMStepTask(i) (RT_MDL->StepTask(i)) 
#endif


#if defined(rtmTaskCounter)  
    #define RTMTaskCounter(i) (rtmTaskCounter(RT_MDL,i)) 
#else
    #define RTMTaskCounter(i) (RT_MDL->TaskCounter(i)) 
#endif

#if defined(rtmCounterLimit)  
    #define RTMCounterLimit(i) (rtmCounterLimit(RT_MDL,i)) 
#else
    #define RTMCounterLimit(i) (RT_MDL->CounterLimit(i)) 
#endif


#if defined(rtmGetTFinal)  
    #define RTMGetTFinal (rtmGetTFinal(RT_MDL)) 
#else
    #define RTMGetTFinal (RT_MDL->getTFinal()) 
#endif


#if defined(rtmGetRTWExtModeInfo)  
    #define RTMGetRTWExtModeInfo (rtmGetRTWExtModeInfo(RT_MDL)) 
#else
    #define RTMGetRTWExtModeInfo (RT_MDL->getRTWExtModeInfo()) 
#endif

#if defined(rtmGetRTWLogInfo)  
    #define RTMGetRTWLogInfo (rtmGetRTWLogInfo(RT_MDL)) 
#else
    #define RTMGetRTWLogInfo (RT_MDL->getRTWLogInfo()) 
#endif

/*===================*
 * Visible functions *
 *===================*/

#if !defined(MULTITASKING) /* single task */

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *   Perform one step of the model.  This function is modeled such that
 *   it could be called from an interrupt service routine (ISR) with minor
 *   modifications.
 */
static void rt_OneStep(void)
{
    /* Disable interrupts here */

    /***********************************************
     * Check and see if base step time is too fast *
     ***********************************************/
    if (OverrunFlags[0]++) {
        RTMSetErrorStatus("Overrun");
    }

    /*************************************************
     * Check and see if an error status has been set *
     * by an overrun or by the generated code.       *
     *************************************************/

    if (RTMGetErrorStatus != NULL) {
        return;
    }

    /* Save FPU context here (if necessary) */
    /* Reenable interrupts here */
    /* Set model inputs here */

    /**************
     * Step model *
     **************/
    MODEL_STEP();

    /* Get model outputs here */

    /**************************
     * Decrement overrun flag *
     **************************/
    OverrunFlags[0]--;

    rtExtModeCheckEndTrigger();

    /* Disable interrupts here */
    /* Restore FPU context here (if necessary) */
    /* Reenable interrupts here */

} /* end rtOneStep */

#else /* multitask */

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *   Perform one step of the model.  This function is modeled such that
 *   it could be called from an interrupt service routine (ISR) with minor
 *   modifications.
 *
 *   Note that error checking is only necessary when this routine is
 *   attached to an interrupt.
 *
 *   Also, you may wish to unroll any or all of for and while loops to
 *   improve the real-time performance of this function.
 */
static void rt_OneStep(void)
{
    int_T i;

    /* Disable interrupts here */

    /***********************************************
     * Check and see if base step time is too fast *
     ***********************************************/
    if (OverrunFlags[0]++) {
        RTMSetErrorStatus("Overrun");
    }

    /*************************************************
     * Check and see if an error status has been set *
     * by an overrun or by the generated code.       *
     *************************************************/

   if (RTMGetErrorStatus != NULL) {
        return;
    }

    /* Save FPU context here (if necessary) */
    /* Reenable interrupts here */
    
    /*************************************************
     * Update EventFlags and check subrate overrun   *
     *************************************************/
    for (i = FIRST_TID+1; i < NUMST; i++) {
        if (RTMStepTask(i) && eventFlags[i]++) {
            OverrunFlags[0]--;
            OverrunFlags[i]++;
            /* Sampling too fast */
            RTMSetErrorStatus("Overrun");
            return;
        }

        if (++(RTMTaskCounter(i)) == RTMCounterLimit(i)){
            (RTMTaskCounter(i)) = 0;
        }

    }

    /* Set model inputs associated with base rate here */

    /*******************************************
     * Step the model for the base sample time *
     *******************************************/
    MODEL_STEP(0);

    /* Get model outputs associated with base rate here */

    /************************************************************************
     * Model step complete for base sample time, now it is okay to          *
     * re-interrupt this ISR.                                               *
     ************************************************************************/
    OverrunFlags[0]--;

    /*********************************************************
     * Step the model for any other sample times (subrates) *
     *********************************************************/
    for (i = FIRST_TID+1; i < NUMST; i++) {
        /*************************************************************
         * If task "i" is running, don't run any lower priority task *
         *************************************************************/
        if (OverrunFlags[i]) return; 

        if (eventFlags[i]) {
            OverrunFlags[i]++;

            /* Set model inputs associated with subrate here */

            /******************************************
             * Step the model for sample time "i" *
             ******************************************/
            MODEL_STEP(i);

            /* Get model outputs associated with subrate here */
            
            /**********************************************
             * Indicate task complete for sample time "i" *
             **********************************************/
            OverrunFlags[i]--;
            eventFlags[i]--;
        }
    }

    rtExtModeCheckEndTrigger();
    /* Disable interrupts here */
    /* Restore FPU context here (if necessary) */
    /* Enable interrupts here */

} /* end rtOneStep */

#endif /* MULTITASKING */

/* Function: rt_InitModel ====================================================
 * 
 * Abstract: 
 *   Initialized the model and the overrun flags
 *
 */
static void rt_InitModel(void)
{
#if defined(MULTITASKING)
    int i;
    for(i=0; i < NUMST; i++) {
        OverrunFlags[i] = 0;
        eventFlags[i] = 0;
    }
#else
    OverrunFlags[0] = 0;
    eventFlags[0] = 0;
#endif

    /************************
     * Initialize the model *
     ************************/
    MODEL_INITIALIZE();
}

/* Function: rt_TermModel ====================================================
 * 
 * Abstract:
 *   Terminates the model and prints the error status
 *
 */
static int_T rt_TermModel(void)
{
    MODEL_TERMINATE();
    
    {

        const char_T *errStatus; 
        errStatus = (const char_T *) (RTMGetErrorStatus) ;
        int_T i = 0;
        
        if (errStatus != NULL && strcmp(errStatus, "Simulation finished")) {
            (void)printf("%s\n", errStatus);
#if defined(MULTITASKING)
            for (i = 0; i < NUMST; i++) {
                if (OverrunFlags[i]) {
                    (void)printf("ISR overrun - sampling rate too"
                                 "fast for sample time index %d.\n", i);
                }
            }
#else
           if (OverrunFlags[i]) { 
               (void)printf("ISR overrun - base sampling rate too fast.\n");
           }
#endif
            return(1);
        }
    }
    
    return(0);
}

/* Function: main =============================================================
 *
 * Abstract:
 *   Execute model on a generic target such as a workstation.
 */
 int_T main(int_T argc, const char *argv[])
 {
     int_T ret;
 
     /* External mode */
     rtParseArgsForExtMode(argc, argv);
 
     /*******************************************
      * warn if the model will run indefinitely *
      *******************************************/
 #ifndef EXT_MODE
 # define EXT_MODE 0
 #endif
 
 #if MAT_FILE==0 && EXT_MODE==0
     (void)printf("warning: the simulation will run with no stop time; "
            "to change this behavior select the 'MAT-file logging' option\n");
     (void)fflush(NULL);
 #endif
 
     /************************
      * Initialize the model *
      ************************/
     rt_InitModel();
 
     /* Prompt user for inputs */
     promptUserInputs(Cosy12_Model4_U);
 
     /* External mode */
     rtSetTFinalForExtMode(&(RTMGetTFinal));
     rtExtModeCheckInit(NUMST);
 
     rtExtModeWaitForStartPkt(RTMGetRTWExtModeInfo,
                              NUMST,
                              (boolean_T *)&(RTMStopRequested));
 
     (void)printf("\n** starting the model **\n");
 
     /***********************************************************************
      * Execute (step) the model.  You may also attach rtOneStep to an ISR, *
      * in which case you replace the call to rtOneStep with a call to a    *
      * background task.  Note that the generated code sets error status    *
      * to "Simulation finished" when MatFileLogging is specified in TLC.   *
      ***********************************************************************/
 
     while (RTMGetErrorStatus == NULL) {
 
         if(RTMStopRequested) break;
 
         rtExtModePauseIfNeeded(RTMGetRTWExtModeInfo,
                                NUMST,
                                (boolean_T *)&(RTMStopRequested));
 
 #if MAT_FILE || EXT_MODE
         if (RTMStopRequested) break;
 #endif
 
         /* external mode */
 
         rtExtModeOneStep(RTMGetRTWExtModeInfo,
                          NUMST,
                         (boolean_T *)&(RTMStopRequested));
         rt_OneStep();
     }
 
     /* Display outputs after the simulation ends */
     displayOutputs(Cosy12_Model4_Y);
 
     /*******************************
      * Cleanup and exit (optional) *
      *******************************/
 
 #ifdef UseMMIDataLogging
     rt_CleanUpForStateLogWithMMI(RTMGetRTWLogInfo);
 #endif
     rt_StopDataLogging(MATFILE,(RTMGetRTWLogInfo));
 
     ret = rt_TermModel();
 
     rtExtModeShutdown(NUMST);
 
     return ret;
 }

/* [EOF] rt_main.cpp */

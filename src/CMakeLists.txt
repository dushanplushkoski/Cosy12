###########################################################################
# CMakeLists.txt generated for component Cosy12_Model4
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(Cosy12_Model4)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


# Set directory properties.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Cosy12_Model4)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR .. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT START_DIR CACHE PATH "")

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "Cosy12_Model4".
add_executable(Cosy12_Model4 ${START_DIR}/Cosy12_Model4_grt_rtw/rt_logging.c
    ${START_DIR}/Cosy12_Model4.cpp
    ${START_DIR}/Cosy12_Model4_capi.cpp
    ${START_DIR}/Cosy12_Model4_data.cpp
    ${START_DIR}/rtGetNaN.cpp
    ${START_DIR}/rt_nonfinite.cpp
    ${START_DIR}/rt_main.cpp)

# Set properties for target "Cosy12_Model4".
set_target_properties(Cosy12_Model4 PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")

# Specify language features required for target "Cosy12_Model4".
target_compile_features(Cosy12_Model4 PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target "Cosy12_Model4".
target_compile_definitions(Cosy12_Model4 PRIVATE -DMODEL=Cosy12_Model4
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DRT
    -DUSE_RTMODEL
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DMAT_FILE=1
    -DONESTEPFCN=1
    -DTERMFCN=1
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0)


# Specify library link dependencies for target "Cosy12_Model4". CMake 
# generator expressions are used to create a CMakeLists.txt file that 
# supports multiple platforms with differently named system library 
# dependencies.
target_link_libraries(Cosy12_Model4 PRIVATE $<$<BOOL:${FOUND_LIBM}>:m>
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:Cosy12_Model4>;--flat,"
                "true"
        >)
    add_custom_command(TARGET Cosy12_Model4
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS Cosy12_Model4.dwarf)
endif()


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET Cosy12_Model4 POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:Cosy12_Model4>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(Cosy12_Model4)
endif()



# Add the shared library target
add_library(libcosy SHARED
    ${START_DIR}/Cosy12_Model4.cpp
    ${START_DIR}/Cosy12_Model4_capi.cpp
    ${START_DIR}/Cosy12_Model4_data.cpp
    ${START_DIR}/rtGetNaN.cpp
    ${START_DIR}/rt_nonfinite.cpp
    ${START_DIR}/rt_logging.c  # Include Simulink Coder runtime source
    ${START_DIR}/rt_main.cpp  # Include Simulink Coder runtime source
)

# Set properties for the shared library
set_target_properties(libcosy PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    OUTPUT_NAME "cosy"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/lib"
)

# Specify language features required for the shared library
target_compile_features(libcosy PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for the shared library
target_compile_definitions(libcosy PRIVATE
    -DMODEL=Cosy12_Model4
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DRT
    -DUSE_RTMODEL
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DMAT_FILE=1
    -DONESTEPFCN=1
    -DTERMFCN=1
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0
)

# Specify include directories for the shared library
target_include_directories(libcosy PRIVATE
    ${START_DIR}
    ${START_DIR}/Cosy12_Model4_grt_rtw
    
)

# Specify library link dependencies for the shared library
target_link_libraries(libcosy PRIVATE
    $<$<BOOL:${FOUND_LIBM}>:m>
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>

)

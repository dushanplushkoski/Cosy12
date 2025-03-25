import ctypes
import os

# Load the shared library
lib = ctypes.CDLL(os.path.abspath("build/lib/libcosy.so"))

# Define function signatures
lib.initializeModel.restype = None
lib.calculateOutputs.argtypes = [
    ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double,
    ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double,
    ctypes.POINTER(ctypes.c_double)
]
lib.calculateOutputs.restype = None

# Initialize the model once
lib.initializeModel()

# Call the function as before


# Debug: Print library function address (to check if it’s loaded correctly)
print("Function loaded at:", lib.calculateOutputs)

# Prepare inputs as C doubles
in1, in2, in3, in4, in5, in6, in7, in8 = 5.0, 2.0, 5.0, 7.0, -10, 55.0, 10, 3.0
inputs = [ctypes.c_double(x) for x in [in1, in2, in3, in4, in5, in6, in7, in8]]

# Create an output buffer (array of 13 doubles)
outputs = (ctypes.c_double * 13)()  # Initialize all elements to 0

# Debug: Print inputs before function call
print("Passing inputs:", [x.value for x in inputs])

# Call the function (pass inputs as separate arguments)
lib.calculateOutputs(inputs[0], inputs[1], inputs[2], inputs[3],
                      inputs[4], inputs[5], inputs[6], inputs[7],
                      outputs)

# Print the outputs
print("Outputs from C++:", [outputs[i] for i in range(13)])

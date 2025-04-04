
import logging
from flask import Flask, request, jsonify, render_template
import ctypes
import os



# Create the Flask app
app = Flask(__name__)

# Load the shared C++ library (update the path as necessary)
lib = ctypes.CDLL(os.path.abspath("build/lib/libcosy.so"))

# Define function signatures
lib.initializeModel.restype = None
lib.calculateOutputs.argtypes = [
    ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double,
    ctypes.c_double, ctypes.c_double, ctypes.POINTER(ctypes.c_double)
]
lib.calculateOutputs.restype = None

# Initialize logging for debugging purposes
logging.basicConfig(level=logging.DEBUG)



@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    try:
        data = request.json
        inputs = [
            data['in1'], data['in2'], data['in3'], data['in4'],
            data['in5'], data['in6']
        ]
        logging.debug(f"Received inputs: {inputs}")

        # Initialize the model once
        lib.initializeModel()

        # Prepare output array
        outputs = (ctypes.c_double * 15)()

        # Call the C++ function
        logging.debug(f"Calling C++ function with inputs: {inputs}")
        lib.calculateOutputs(*inputs, outputs)
        logging.debug("C++ function call completed successfully.")

        # Convert outputs to a list
        outputs_list = [outputs[i] for i in range(15)]

        return jsonify({'outputs': outputs_list})

    except Exception as e:
        logging.error(f"Error during calculation: {e}")
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)

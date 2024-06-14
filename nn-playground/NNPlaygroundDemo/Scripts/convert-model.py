# Converts the model from Keras format into the ORT (onnx) format. 

import tensorflow as tf
import tf2onnx
import onnx

model = tf.keras.models.load_model("mnist.keras")
model.output_names=['output']
onnx_model, _ = tf2onnx.convert.from_keras(
    model,
    input_signature=[tf.TensorSpec([1, 28, 28, 1], tf.float32, name='input')],
)

# Print out the dimensions of all inputs and outputs
inputs = {}
for input in onnx_model.graph.input:
    shape              = str(input.type.tensor_type.shape.dim)
    inputs[input.name] = [int(s) for s in shape.split() if s.isdigit()]
    
outputs = {}
for output in onnx_model.graph.output:
    shape                = str(output.type.tensor_type.shape.dim)
    outputs[output.name] = [int(s) for s in shape.split() if s.isdigit()]
print("Inputs: ", inputs, "\nOutputs: ", outputs)

onnx.save(onnx_model, "mnist.onnx")
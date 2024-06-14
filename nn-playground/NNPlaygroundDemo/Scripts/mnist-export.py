# Exports the desired images from the MNIST dataset in PNG format.

import tensorflow as tf
import PIL

(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()

for i in range(30, 50):
    image = PIL.Image.fromarray(x_train[i])
    image.save(f"../Samples/train{i}.png")
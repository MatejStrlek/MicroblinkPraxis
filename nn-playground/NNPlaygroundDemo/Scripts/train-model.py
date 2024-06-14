# Trains the MNIST model and saves it in the Keras format.

import numpy as np
import tensorflow as tf

(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()

# Scale images to the [0, 1] range.
x_train = x_train.astype("float32") / 255 
x_test  = x_test.astype("float32")  / 255

# Make sure images have shape (28, 28, 1).
x_train = np.expand_dims(x_train, -1)
x_test  = np.expand_dims(x_test, -1)

model = tf.keras.Sequential([
    tf.keras.layers.Input(shape=(28, 28, 1), name='input'),
    tf.keras.layers.Conv2D(64, kernel_size=(3, 3), activation="relu"),
    tf.keras.layers.Conv2D(64, kernel_size=(3, 3), activation="relu"),
    tf.keras.layers.MaxPooling2D(pool_size=(2, 2)),
    tf.keras.layers.Conv2D(128, kernel_size=(3, 3), activation="relu"),
    tf.keras.layers.Conv2D(128, kernel_size=(3, 3), activation="relu"),
    tf.keras.layers.GlobalAveragePooling2D(),
    tf.keras.layers.Dropout(0.5),
    tf.keras.layers.Dense(10, activation="softmax", name='output'),
])
model.summary()

model.compile(
    loss=tf.keras.losses.SparseCategoricalCrossentropy(),
    optimizer=tf.keras.optimizers.Adam(),
    metrics=[tf.keras.metrics.SparseCategoricalAccuracy(name="acc")]
)

history = model.fit(
    x_train,
    y_train,
    batch_size=128,
    epochs=20,
    validation_split=0.15,
    callbacks=[tf.keras.callbacks.EarlyStopping(monitor="val_loss", patience=2)],
)
score = model.evaluate(x_test, y_test, verbose=1)
model.save("mnist.keras")
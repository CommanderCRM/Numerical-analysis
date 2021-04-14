# -*- coding: utf-8 -*-

import numpy as np

ITERATION_LIMIT = 100


A = np.array([[0.94, -0.4, -0.09],
              [0.38, -0.19, 0.93],
              [0.7, 0.8, 3.14]])

b = np.array([2.5, 2.3, 3.3])

print("Система уравнений:")
for i in range(A.shape[0]):
    row = ["{0:3g}*x{1}".format(A[i, j], j + 1) for j in range(A.shape[1])]
    print("[{0}] = [{1:3g}]".format(" + ".join(row), b[i]))

x = np.zeros_like(b)
for it_count in range(1, ITERATION_LIMIT):
    x_new = np.zeros_like(x)
    print("Текущее решение {0}: {1}".format(it_count, x))
    for i in range(A.shape[0]):
        s1 = np.dot(A[i, :i], x_new[:i])
        s2 = np.dot(A[i, i + 1:], x[i + 1:])
        x_new[i] = (b[i] - s1 - s2) / A[i, i]
    if np.allclose(x, x_new, rtol=1e-8):
        break
    x = x_new

print("Решение: {0}".format(x))
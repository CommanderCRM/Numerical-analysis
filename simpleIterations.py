# -*- coding: utf-8 -*-

import numpy as np

ITERATION_LIMIT = 100


A = np.array([[0.94, -0.4, -0.09],
              [0.38, -0.19, 0.93],
              [0.7, 0.8, 3.14]])

b = np.array([2.5, 2.3, 3.3])


print("Система:")
for i in range(A.shape[0]):
    row = ["{}*x{}".format(A[i, j], j + 1) for j in range(A.shape[1])]
    print(" + ".join(row), "=", b[i])
print()

x = np.zeros_like(b)
for it_count in range(ITERATION_LIMIT):
    print("Текущее решение:", x)
    x_new = np.zeros_like(x)

    for i in range(A.shape[0]):
        s1 = np.dot(A[i, :i], x[:i])
        s2 = np.dot(A[i, i + 1:], x[i + 1:])
        x_new[i] = (b[i] - s1 - s2) / A[i, i]

    if np.allclose(x, x_new, atol=1e-10, rtol=0.):
        break

    x = x_new

print("Решение:")
print(x)
# -*- coding: utf-8 -*-

import numpy as np
a = np.array([[0.94, -0.4, -0.09], [0.38, -0.19, 0.93], [0.7, 0.8, 3.14]])
b = np.array([2.5, 2.3, 3.3])

inversedMatrix = np.linalg.inv(a) # Нахождение обратной матрицы
print ('Обратная матрица = ', inversedMatrix)

solution = np.dot(inversedMatrix, b) # Умножение обратной матрицы на вектор свободных членов

print ('Ответ = ', solution)
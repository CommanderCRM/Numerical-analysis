import numpy
import copy


def gaussFunc(a):
    eps = 0.01

    a = numpy.array(a)

    len1 = len(a[:, 0])
    len2 = len(a[0, :])

    for g in range(len1):

        max = abs(a[g][g])
        my = g
        t1 = g
        while t1 < len1:
            if abs(a[t1][g]) > max:
                max = abs(a[t1][g])
                my = t1
            t1 += 1

        if abs(max) < eps:
            raise DetermExeption("Проверьте определитель")

        if my != g:
            b = copy.deepcopy(a[g])
            a[g] = copy.deepcopy(a[my])
            a[my] = copy.deepcopy(b)

        amain = float(a[g][g])

        z = g
        while z < len2:
            a[g][z] = a[g][z] / amain
            z += 1

        j = g + 1

        while j < len1:
            b = a[j][g]
            z = g

            while z < len2:
                a[j][z] = a[j][z] - a[g][z] * b
                z += 1
            j += 1

    a = backTrace(a, len1, len2)

    return a


class DetermExeption(Exception):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return repr(self.value)


def backTrace(a, len1, len2):
    a = numpy.array(a)
    i = len1 - 1
    while i > 0:
        j = i - 1

        while j >= 0:
            a[j][len1] = a[j][len1] - a[j][i] * a[i][len1]
            j -= 1
        i -= 1
    return a[:, len2 - 1]


def vectorN(c, a, len1, vectB):
    c = numpy.array(c)
    a = numpy.array(a)
    vectB = numpy.array(vectB)

    b = numpy.zeros((len1))

    i = 0


    while i<len1:
        j = 0
        while j<len1:

            b[i]+=c[i][j]*a[j]

            j+=1

        i=i+1



    c = copy.deepcopy(b)
    print("!")

    for i in range(len1):
        c[i] = abs(c[i] - vectB[i])

    return c
a = numpy.array([[0.94, -0.4, -0.09, 2.5],
                [0.38, -0.19 , 0.93, 2.3],
                [0.7, 0.8, 3.14, 3.30]])

print(a)
print("\n")

b = gaussFunc(a)
print("Ответ:")
print(b)

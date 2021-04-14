from functools import reduce
from operator import mul, sub
 
def column(row):
    i = 0
    n = len(row)
    while not row[i] and i < n:
        i += 1
    return i if i < n else -1
 
def sign(indexes):
    s = sum((0, 1)[x < y] for k, y in enumerate(indexes) for x in indexes[k+1:])
    return ((s + 1) % 2 - s % 2)
 
def det(matrix):
    M = matrix[:]
    n = len(M)
 
    indexes = [0 for _ in range(n)]
 
    for i in range(n):
        k = column(M[i])
        for j in (x for x in range(n) if x != i):
            M[j] = tuple(map(sub, M[j],
                             map(mul, M[i], [M[j][k] / M[i][k]] * (n+1))))
        indexes[i] = k
 
    return reduce(mul, (M[i][indexes[i]] for i in range(n)), 1) * sign(indexes)
 
def kramer(les):
    """ Решение методом Крамера """
 
    n = len(les)
    tmp = list(zip(*les))
    b = tmp[-1]
    del tmp[-1]
 
    delta = det(tmp)
    if not delta:
        raise RuntimeError("Решения нет")
 
    result = []
    for i in range(n):
        a = tmp[:]
        a[i] = b
        result.append(det(a) / delta)
    return result
 
if "__main__" == __name__:
    matrix = [(94, -40, -9, 250),
                  (38 ,-19, 93, 230),
                  (70 ,80 ,314 ,330)]
 
    print(kramer(matrix))
    print("=" * 10)
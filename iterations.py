import math

def f(x):
    return math.sqrt(x-4) - x + 5

iterationCount = 0
    
def iterations(f, x0, a, b, eps, f1):
    global iterationCount
    while abs(a - x0) > eps and abs(b - x0) > eps:
        x = x0 + f1*f(x0)
        if abs (x - x0) < eps:
            break
        else:
            x0 = x
        iterationCount += 1
        print(round(x, 4))

answer = iterations(f, 6.5, 6, 7, 0.01, 0.5)
print('Количество итераций:', iterationCount)

import math
 
def f(x):
    return math.sqrt(x-4) - x + 5

iterationCount = 0

def dich(f, a, b, eps=0.01):
    global iterationCount
    while abs(b - a) > eps:
        iterationCount += 1
        x = (a + b) / 2.0
        fx = f(x)
        fa = f(a)
        if (fx < 0 and fa < 0) or (fx > 0 and fa > 0):
            a = x
        else:
            b = x
    return x
 
x = dich(f, 6, 7)

print('Количество итераций:', iterationCount)
print('Ответ:', round(x, 4))
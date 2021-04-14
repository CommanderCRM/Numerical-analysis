import math

def newton(f, Df, x0, eps, max_iter):
    xn = x0
    for n in range(0, max_iter):
        fxn = f(xn)
        if abs(fxn) < eps:
            print('Решение найдено после',n,'итераций.')
            return xn
        Dfxn = Df(xn)
        if Dfxn == 0:
            print('Производная равна 0. Решений нет.')
            return None
        xn = xn - fxn / Dfxn
    print('Превышено максимальное число итераций. Решений нет.')
    return None

def f(x):
    return math.sqrt(x-4) - x + 5

def Df(x):
    return -1 + 1/(2 * math.sqrt(-4 + x))

x = newton(f, Df, 7, 0.01, 10)
print(round(x,4))
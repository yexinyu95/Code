def countpi(n):
    ''' use arctan's taylor series to count pi '''
    pi = 1
    if n < 1:
        return pi * 4
    else:
        for i in range(1, n):
            if i % 2 == 0:
                pi = pi + 1 / (2 * i + 1)
            else:
                pi = pi - 1 / (2 * i + 1)


        return pi * 4

def factorial(n):
    ''' use loop to count factorial '''
    fac = 1
    if n < 1:
        return 1
    else:
        for i in range(1, n + 1):
            fac = fac * i
        return fac


def extendcombine(n, r):
    ''' count extended combine number {n choose r},'''
    frac = 1
    i = 0
    while i < r:
        frac = frac * (n - i)
        i = i + 1

    divide = factorial(r)
    combinenum = frac / divide

    return combinenum

def counte(n):
    ''' use exp's taylor series to count e '''
    e = 1
    if n < 1:
        return 1
    else:
        for i in range(1, n):
            e = e + (1 / factorial(i))
        return e

print(extendcombine(-2, 2))

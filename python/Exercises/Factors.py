def factors(n):
    '''check input number's factor'''
    factor = 1
    while factor < (n / factor):
        factor = factor + 1
        while (n % factor == 0):
            n = n / factor
            print(factor)
    if n > 1:
        print(n)

factors(1248)



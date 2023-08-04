import time

def prime_number(num):
    list1 = []
    for i in range (2, num):
        is_prime = True
        for j in range(2, i):
            if (i % j) == 0:
                is_prime = False
                break
        if is_prime:
            list1.append(i)
    return(list1)

time_start = time.time()
print(prime_number(100000))
time_end   = time.time()
print(time_end - time_start)

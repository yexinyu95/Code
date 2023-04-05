import time

cubelist = []
for i in range(0, 100):
    cubelist.append(i ** 3)


def cubenumber(num):
    numbers1  = []
    for j in range(0, 100):
        if num - cubelist[j] > num // 2:
            if (num - cubelist[j]) in cubelist:
                numbers1.append((num, (cubelist[j], num - cubelist[j])))

    return numbers1

'''timea = time.time()
print(cubenumber(262656))
timeb = time.time()
timec  = timeb - timea
print(timec)'''


def ramanujan(num):
    numbers2 = []
    for i in range(0, num):
        if len(cubenumber(i)) > 1:
            numbers2.append(i)

    return numbers2


time4a = time.time()
print(ramanujan(12500))
time4b = time.time()
time4  = time4b - time4a

'''
time5a = time.time()
print(ramanujan(72500))
time5b = time.time()
time5  = time5b - time5a

time6a = time.time()
print(ramanujan(360000))
time6b = time.time()
time6  = time6b - time6a
'''
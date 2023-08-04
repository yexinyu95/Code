spam  = ['1', '2', '1', '2', '1', '3', '1', '3']

position = []

for i in range(0, len(spam)):
    if ('1' == spam[i]):
        position.append(i+1)

print(position)

def threexplus1(num):
    changelist = []

    while num != 1:
        if num % 2 == 0:
            num = num / 2
            changelist.append(num)
        else:
            num = 3 * num + 1
            changelist.append(num)
    return(changelist)

print(threexplus1(103418))
    
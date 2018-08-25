while True:
    temp = input()
    if temp == '0 0':
        break
    a, b = [int(x) for x in temp.split()]
    whole = a // b
    remain = a % b
    print(str(whole) + ' ' + str(remain) + ' / ' + str(b))

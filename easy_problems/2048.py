def updateRow(array):
    newArray = []
    output = []
    for i in array:
        if i != 0:
            newArray.append(i)

    for i in range(len(newArray) - 1):
        if newArray[i] == newArray[i + 1]:
            newArray[i] = 2 * newArray[i]
            newArray[i + 1] = 0
            i += 1

    for i in newArray:
        if i != 0:
            output.append(i)

    return output + [0] * (4 - len(output))

def newState(array):
    temp = []
    for i in array:
        temp.append(updateRow(i))
    return temp

def printArray(array):
    for i in array:
        print(" ".join(map(str,i)))

def transDirec(array, direc):
    transpose = []
    for i in range(4):
        transpose.append([0] * 4)

    if direc == 0:
        return array
    if direc == 1:
        for i in range(4):
            for j in range(4):
                transpose[i][j] = array[j][i]
        return transpose
    if direc == 2:
        for i in range(4):
            for j in range(4):
                transpose[i][j] = array[i][3 - j]
        return transpose
    if direc == 3:
        return transDirec(transDirec(array, 1),2)

def reverse(array, direc):
    if direc != 3:
        return transDirec(array, direc)
    else:
        return transDirec(transDirec(array, 2), 1)

array = []
for i in range(4):
    line = [int(x) for x in input().split()]
    array.append(line)

direc = int(input())

printArray(reverse(newState(transDirec(array, direc)), direc))

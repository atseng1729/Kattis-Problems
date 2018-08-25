def solution(arr1, arr2):
    output1 = dict()
    for i in arr1:
        if i not in output1.keys():
            output1[i] = 1
        else:
            output1[i] += 1
    output2 = dict()
    for i in arr2:
        if i not in output2.keys():
            output2[i] = 1
        else:
            output2[i] += 1

    ans = 0
    for i in output1.keys():
        if i not in output2.keys(): pass
        else: ans += min(output1[i], output2[i])
    return ans

if __name__ == "__main__":
    n = int(input())
    arr1 = []
    arr2 = []
    for i in range(n):
        arr1.append(input())
    for i in range(n):
        arr2.append(input())

    print(solution(arr1, arr2))

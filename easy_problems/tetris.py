C, P = [int(x) for x in input().split()]
vals = [int(x) for x in input().split()]

def check(pat):
    global vals
    answer = 0
    patlen = len(pat)
    for i in range(len(vals) - patlen + 1):
        if ([vals[i+j] + pat[j] for j in range(patlen - 1)] == [vals[i+j+1] + pat[j+1] for j in range(patlen - 1)]):
            answer += 1
    return answer

patterns = [[[0],[0,0,0,0]]
    ,[[0,0]]
    ,[[1,1,0],[0,1]]
    ,[[0,1,1],[1,0]]
    ,[[0,0,0],[1,0],[0,1],[0,1,0]]
    ,[[0,0,0],[0,0],[1,0,0],[0,2]]
    ,[[0,0,0],[0,0],[0,0,1],[2,0]]]

answer = 0
for pat in patterns[P - 1]:
    answer += check(pat)
print(answer)

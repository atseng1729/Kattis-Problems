input()
trees = sorted([int(x) for x in input().split()], reverse = True)

ans = 0

for i in range(len(trees)):
    temp = i + 1 + trees[i]
    if temp > ans: ans = temp

print(ans + 1)

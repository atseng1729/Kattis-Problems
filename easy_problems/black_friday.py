input()
values = [int(x) for x in input().split()]

visited = [0] * 6
for i in values:
    visited[i - 1] += 1

if 1 not in visited:
    print('none')
else:
    for i in range(5,-1, -1):
        if visited[i] == 1:
            max_value = i + 1
            break

    print(values.index(max_value) + 1)

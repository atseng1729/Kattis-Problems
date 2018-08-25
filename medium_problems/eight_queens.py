queens = []
ans = 'valid'
for y in range(8):
    temp = input()
    if temp.count('*') != 1:
        ans = 'invalid'
        break
    else:
        x = temp.index('*')
        queens.append((x, y))

columns = [0] * 8
diag1 = [0] * 15
diag2 = [0] * 15
for x, y in queens:
    if columns[x] != 0:
        ans = 'invalid'
        break
    else:
        columns[x] += 1

    if diag1[x - y + 7] != 0:
        ans = 'invalid'
        break
    else:
        diag1[x - y + 7] += 1

    if diag2[x + y] != 0:
        ans = 'invalid'
        break
    else:
        diag2[x + y] += 1
print(ans)



'*.......'
'..*.....'
'....*...'
'......*.'
".*......"
'.......*'
'.....*..'
'...*....'

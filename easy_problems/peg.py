ans = 0
board = []
for i in range(7):
    board.append(input())

for i in range(7):
    for j in range(5):
        if board[i][j:j + 3] == "oo." or board[i][j:j+3] == ".oo": ans += 1
        vert_str = board[j][i] + board[j + 1][i] + board[j + 2][i]
        if vert_str == "oo." or vert_str == ".oo": ans += 1

print(ans)

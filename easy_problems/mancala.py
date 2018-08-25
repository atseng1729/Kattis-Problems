
boards = [[1]]

for i in range(2001):
    prev = boards[-1]
    length = len(prev)
    zero_index = 0
    while zero_index != length and prev[zero_index] != 0:
        zero_index += 1
    new = list(prev)
    for j in range(zero_index):
        new[j] -= 1
    if zero_index == length:
        new.append(length + 1)
    else:
        new[zero_index] = zero_index + 1
    boards.append(new)

for i in range(int(input())):
    K, N  = [int(x) for x in input().split()]
    board = boards[N - 1]
    print(K, len(board))
    print(' '.join(map(str, board)))

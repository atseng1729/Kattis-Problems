def new_board():
    return [0,0,0,0,0,0,0,0,0]

def flip(board, n):
    board[n] = 1 - board[n]
    if n - 3 >= 0:
        board[n - 3] = 1 - board[n - 3]
    if (n % 3) - 1 >= 0:
        board[n - 1] = 1 - board[n - 1]
    if n + 3 <= 8:
        board[n + 3] = 1 - board[n + 3]
    if (n % 3) + 1 <= 2:
        board[n + 1] = 1 - board[n + 1]
    return board

possible_boards = {tuple(new_board()): 0}

for i in range(9):
    new_possible_boards = dict()
    for board in possible_boards:
        new_possible_boards[tuple(flip(list(board),i))] = possible_boards[board] + 1
    possible_boards.update(new_possible_boards)

cases = int(input())
for _ in range(cases):
    cur_board = []
    for _ in range(3):
        temp = input()
        for i in temp:
            if i == '*':
                cur_board.append(1)
            else:
                cur_board.append(0)
    print(possible_boards[tuple(cur_board)])

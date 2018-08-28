students, num_commands = [int(x) for x in input().split()]
commands = []
undo_flag = 0

for command in input().split():
    if command == 'undo':
        undo_flag = 1
    elif undo_flag:
        for i in range(int(command)):
            commands.pop()
        undo_flag = 0
    else:
        commands.append(int(command))

print(sum(commands) % students)

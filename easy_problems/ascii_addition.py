numbers = ['xxxxxx...xx...xx...xx...xx...xxxxxx'
    , '....x....x....x....x....x....x....x', 'xxxxx....x....xxxxxxx....x....xxxxx'
    , 'xxxxx....x....xxxxxx....x....xxxxxx', 'x...xx...xx...xxxxxx....x....x....x'
    , 'xxxxxx....x....xxxxx....x....xxxxxx', 'xxxxxx....x....xxxxxx...xx...xxxxxx'
    , 'xxxxx....x....x....x....x....x....x', 'xxxxxx...xx...xxxxxxx...xx...xxxxxx'
    , 'xxxxxx...xx...xxxxxx....x....xxxxxx', '.......x....x..xxxxx..x....x.......']

line = input()
length = int(len(line) / 6 + 1)
vals = ['' for _ in range(length)]

for i in range(7):
    for j in range(length):
        vals[j] += line[6 * j: 6 * j + 5]
    if i != 6:
        line = input()

temp_string = ''
total = 0
for i in vals:
    temp = numbers.index(i)
    if temp == 10:
        total += int(temp_string)
        temp_string = ''
    else:
        temp_string += str(temp)

total += int(temp_string)
total_string = [numbers[int(c)] for c in str(total)]

for i in range(7):
    temp = []
    for j in range(len(total_string)):
        temp.append(total_string[j][5 * i: 5 * i + 5])
    print('.'.join(temp))

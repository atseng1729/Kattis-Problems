word = input()
output = ['','','','','']
length = len(word)

output[0] += '.'
output[1] += '.'
output[2] += '#'
output[3] += '.'
output[4] += '.'
for i in range(length):
    if i % 3 == 2:
        output[0] += '.*..'
        output[1] += '*.*.'
        output[3] += '*.*.'
        output[4] += '.*..'
    else:
        output[0] += '.#..'
        output[1] += '#.#.'
        output[3] += '#.#.'
        output[4] += '.#..'

for i in range(length):
    if i % 3 == 2 or (i % 3 == 1 and i != length - 1):
        output[2] += ('.{}.*'.format(word[i]))
    else:
        output[2] += ('.{}.#'.format(word[i]))

print('\n'.join(output))

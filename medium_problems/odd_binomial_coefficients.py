import math

def count_odd(number):
    if (number == 0): return 0
    if (number == 1): return 1
    highest_pow = math.floor(math.log(number, 2))
    return 3 ** highest_pow + 2 * count_odd(number - (1 << highest_pow))


n = int(input())

print(count_odd(n))

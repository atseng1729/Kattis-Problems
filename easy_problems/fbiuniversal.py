base27 = '0123456789ACDEFHJKLMNPRTVWX'
letters = 'BGIOQSUYZ'
replace = '8C1005VV2'
mult = [2,4,5,7,8,10,11,13]

def find_val(letter):
    for i in range(9):
        if letter == letters[i]:
            letter = replace[i]
            break
    return base27.find(letter)

for i in range(int(input())):
    num, str = input().split()
    decimal = 0
    check = 0
    for j in range(8):
        # replace letter if in letters
        val = find_val(str[j])
        decimal = 27 * decimal + val
        check += mult[j] * val
    if find_val(str[8]) == (check % 27):
        print(num, decimal)
    else:
        print(num, 'Invalid')

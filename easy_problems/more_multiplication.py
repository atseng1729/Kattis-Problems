def printMult(a, b):
    product = str(int(a) * int(b))
    length1 = len(a)
    length2 = len(b)
    length3 = len(product)
    product_str = ' ' * (length1 + length2 - length3) + product

    print('+' + '-' * (4 * length1 + 3) + '+')
    print('|   ' + '   '.join(a) + '   |')

    counter = 0
    for b_digit in b:
        print('| ' + '+---' * length1 + '+ |')

        print('|{}'.format('/' if counter + length3 > length1 + length2 else ' '), end = '')
        for dig in [int(b_digit) * int(a_digit) // 10 for a_digit in a]:
            print('|{} /'.format(dig), end = '')
        print('| |')

        print('| ' + '| / ' * length1 + '|' + b_digit + '|')

        print('|{}'.format(product_str[counter]), end = '')
        for dig in [int(b_digit) * int(a_digit) % 10 for a_digit in a]:
            print('|/ {}'.format(dig), end = '')
        print('| |')
        counter += 1

    print('| ' + '+---' * length1 + '+ |')
    print('|{} {}    |'.format('/' if length3 > length1 else ' '
        , ' / '.join(product[length3 - length1:])))
    print('+' + '-' * (4 * length1 + 3) + '+')

if __name__=="__main__":
    while True:
        a, b = input().split()
        if a != '0' and b != '0':
            printMult(a, b)
        else:
            break

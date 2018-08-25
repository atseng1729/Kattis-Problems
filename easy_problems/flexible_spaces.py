# Problem Link:
# https://open.kattis.com/contests/ojax3p/problems/flexible

length, count = [int(x) for x in input().split()]
partitions = [0] * (count + 1)
temp = [int(x) for x in input().split()]

for i in range(count):
    if i == 0:
        partitions[i] = temp[i]
    else:
        partitions[i] = temp[i] - temp[i - 1]
    if i == (count - 1):
        partitions[i + 1] = length - temp[i]

possible_widths = set()
for i in partitions:
    possible_widths.add(i)
    
new_partitions = list(partitions)
while len(partitions) > 1:
    new_partitions.pop()
    for i in range(len(new_partitions)):
        new_partitions[i] += partitions[i + 1]
        possible_widths.add(new_partitions[i])
    del partitions[0]

ans_list = sorted(list(possible_widths))
print(' '.join(map(str, ans_list)))

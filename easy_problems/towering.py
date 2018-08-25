inputs = [int(x) for x in input().split()]
boxes = inputs[:6]
boxes = sorted(boxes, reverse = True)
height1 = inputs[6] - boxes[0];
sec = -1
third = -1
switch = 0

for i in range(1,5):
    for j in range(i + 1, 6):
        if height1 == boxes[i] + boxes[j]:
            sec = i
            third = j
            break
count = 0
if sec == -1:
    switch = 1
    height2 = inputs[7] - boxes[0]
    for i in range(1,5):
        for j in range(i + 1, 6):
            if height2 == boxes[i] + boxes[j]:
                sec = i
                third = j
                break

tower1 = [boxes[0], boxes[sec], boxes[third]]
tower2 = []
for k in range(6):
    if k not in [0,sec,third]:
        tower2.append(boxes[k])

towers = tower1 + tower2 if not switch else tower2 + tower1

print(' '.join(map(str, towers)))

l = [[0]*5 for i in range(3)]

for i in range(3):
    l[i][4] = i+1

for i in range(int(input())):
    a, b, c = map(int, input().split())

    l[0][0] -= a
    l[1][0] -= b
    l[2][0] -= c

    l[0][4-a] -= 1
    l[1][4-b] -= 1
    l[2][4-c] -= 1

l.sort()

if l[0][:4] != l[1][:4]: print(l[0][4], -l[0][0])
else: print(0, -l[0][0])
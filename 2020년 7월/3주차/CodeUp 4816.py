T = int(input())
btn = [300, 60, 10]
res = [0]*3

for i in range(3):
    res[i] = T//btn[i]
    T %= btn[i]

if T == 0:
    for i in res:
        print(i, end=' ')
else:
    print(-1)
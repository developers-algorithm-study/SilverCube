N = int(input())
A, B = map(int, input().split())
C = int(input())
l = []

for i in range(N):
    l.append(int(input()))

l.sort(reverse=True)
kcal = res = 0

for i in range(N):
    kcal += l[i]
    res = max(res, (C+kcal)/(A+B*(i+1)))

print(int(res))
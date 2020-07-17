a, b = map(int, input().split())
S = 0

for i in range(a, b+1):
    if i%3 == 0:
        S += i

print(S)
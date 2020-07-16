H, S, t = map(int, input().split())
D = int(input())
res = (H-D*t+1/100*S*D*t)/(1/100*S*D*t)*100

if res <= 0: print("O")
elif res > 100: print("X")
else: print("%.6f" % res)
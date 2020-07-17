from math import factorial as f

def C(n, r):
    return f(n)//f(r)//f(n-r)

n = int(input())

for r in range(n+1):
    nCr = C(n, r)
    
    if nCr != 1:
        print(end="%s*" % nCr)
    
    if r == 0:
        print(end="a^%s" % (n-r))
    elif n-r == 0:
        print(end="b^%s" % r)
    else:
        print(end="a^%s*b^%s" % (n-r, r))
    
    if r != n:
        print(end="+")
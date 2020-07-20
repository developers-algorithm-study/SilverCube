s = input()
y, m, d, g = s[:2], s[2:4], s[4:6], s[7]

if g <= '2': y = "19"+y
else: y = "20"+y

if int(g)%2: g = 'M'
else: g = 'F'

print("%s/%s/%s %s" % (y, m, d, g))
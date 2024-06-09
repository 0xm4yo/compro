a, b = map(int, input().split())
h ,w = map(int, input().split())

a1 = h/a
b1 = w/b
c1 = min(a1,b1)
s1 = c1*a*c1*b

a2 = w/a
b2 = h/b
c2 = min(a2,b2)
s2 = c2*a*c2*b

if s1 == s2:
    print('Same')
elif s1 > s2:
    print('Non-rotating')
else:
    print('Rotating')
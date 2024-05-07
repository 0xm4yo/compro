import math
A, B = map(int, input().split())

def f(x):
    return B * x + A / math.sqrt(x+1)
    
low = 0
high = A / B

while high - low > 2:
    d = high - low
    m1 = low + d / 3
    m2 = high - d / 3
    if f(m1) >= f(m2):
        low = m1
    else:
        high = m2

_min = A
for x in range(max(0, int(low)-3), min(int(high)+3, 10**18)):
    _min = min(_min, f(x))
print(_min)
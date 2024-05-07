import sys
sys.setrecursionlimit(10**5)

n = int(input())

x = 1000000000000000000000000000000000000000000000000000000000

for a in range(1000010):
    l = a-1
    r = 100000000
    while r-l>1:
        mid = (l+r)//2
        if (a*a*a+a*a*mid+a*mid*mid+mid*mid*mid < n):
            l = mid
        else:
            r = mid
    x = min(x, a*a*a+a*a*r+a*r*r+r*r*r)
print(x)


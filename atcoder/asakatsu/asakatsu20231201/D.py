import sys
sys.setrecursionlimit(10**5)

n = int(input())
ans = 10000000000000000000000000000
for a in range(1000001):
    if a*a*a > n:
        break
    l = -1
    r = 1000001
    while (r-l>1):
        mid = (l+r)//2
        if a*a*a+a*a*mid+a*mid*mid+mid*mid*mid >= n:
            r = mid
        else:
            l = mid
    b = r
    if (a>b):
        break
    ans = min(ans, a*a*a+a*a*b+a*b*b+b*b*b)

print(ans)
        

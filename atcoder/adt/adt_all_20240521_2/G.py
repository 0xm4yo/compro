n = int(input())
ans = 10**18+1
INF = 10**10
for a in range(0, 10**6+1):
    l = a-1
    r = INF
    while r-l>1:
        mid = (l+r)//2
        if a*a*a + a*a*mid + a*mid*mid + mid*mid*mid >= n:
            r = mid
        else:
            l = mid
    ans = min(ans, a*a*a + a*a*r + a*r*r + r*r*r)

print(ans)
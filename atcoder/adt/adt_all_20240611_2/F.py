x,a,d,n = map(int,input().split())

l = 0
r = n
while r-l>1:
    mid = (r+l)//2
    tmp = a + (mid-1)*d
    if d >= 0:
        if tmp < x:
            l = mid
        else:
            r = mid
    else:
        if tmp < x:
            r = mid
        else:
            l = mid
ans = 10e19
for i in range(max(1,r-3), min(r+3,n)+1):
    ans = min(ans, abs(x - (a + (i-1)*d)))

print(ans)
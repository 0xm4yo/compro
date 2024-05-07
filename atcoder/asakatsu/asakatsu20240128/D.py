n,m=map(int,input().split())    

if (n*n<m):
    print(-1)
    exit()

ans = 1000000000000000000000
for a in range(1,1000010):
    if (a>n):
        break
    b = (m+a-1)//a
    if (b<=n):
        ans = min(ans, a*b)
print(ans)


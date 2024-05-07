n,m = map(int, input().split())

if (n*n<m):
    print(-1)
    exit()

ans = 100010001010101010
for a in range(1, 1000100):
    if (a>n):
        break

    b = (m+a-1)//a
    if (b>n):
        continue
    ans = min(ans, a*b)
print(ans)

n, m = map(int, input().split())
s = [input() for _ in range(n)]
t = [input() for _ in range(m)]

ans = 0
for ss in s:
    sss = ss[3:]
    if sss in t:
        ans += 1
print(ans)
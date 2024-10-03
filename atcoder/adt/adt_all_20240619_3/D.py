n,m = map(int,input().split())
c = list(input().split())
d = list(input().split())
p = list(map(int,input().split()))

from collections import defaultdict
di = defaultdict(int)
for i in range(m):
    di[d[i]] = p[i+1]

ans = 0
for cc in c:
    if di[cc] == 0:
        ans += p[0]
    else:
        ans += di[cc]
print(ans)

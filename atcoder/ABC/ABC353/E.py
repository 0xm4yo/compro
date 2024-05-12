n = int(input())
s = list(input().split())

m = 697147581815999

from collections import defaultdict

d = defaultdict(int)
b = 107

ans = 0
for i in range(n):
    now = 0
    keta = 1
    for j in range(len(s[i])):
        now += (ord(s[i][j])-ord('a')+1) * keta
        now %= m
        keta *= b
        keta %= m
        ans += d[now]
        d[now] += 1

print(ans)
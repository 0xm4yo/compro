n = int(input())
a = list(map(int,input().split()))
b = max(a)
ans = 0
for aa in a:
    if aa==b:
        continue
    ans = max(ans, aa)
print(ans)
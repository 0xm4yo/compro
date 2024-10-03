n = int(input())
import math
ans = 0
rnow = n
for l in range(1, int(math.sqrt(n)+1)):
    rnex = n // (l+1)
    cnt = rnow - max(l,rnex)
    if cnt:
        ans += cnt * l
    ans += n // l
    rnow = rnex

print(ans)

# ans2 = 0
# for i in range(1,n+1):
#     ans2 += n//i
# print(ans2)
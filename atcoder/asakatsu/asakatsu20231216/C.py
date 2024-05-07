import sys
sys.setrecursionlimit(10**5)

n = int(input())
dp = [0] * 20

dp[0] = 1
for i in range(1,20):
    if (pow(10,i)-1<n):
        dp[i] = pow(10,i) - pow(10,i-1)
    else:
        dp[i] = n - pow(10,i-1) + 1
        break

ans = 0
mod = 998244353
for i in range(1,20):
    ans += (1+dp[i])*dp[i]//2
    ans %= mod
print(ans)

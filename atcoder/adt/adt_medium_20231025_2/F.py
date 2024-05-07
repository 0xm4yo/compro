import sys
sys.setrecursionlimit(10**5)

n=int(input())
cnt=1
n2 = n
ans = 0
mod = 998244353
while(n2):
    st = pow(10,cnt-1)
    lt = pow(10,cnt)-1
    if (lt<n):
        ans += (lt-st+1)*(1+lt-st+1)//2
        ans %= mod
    else:
        ans += (n-st+1)*(1+n-st+1)//2
        ans %= mod
    n2//=10
    cnt += 1
print(ans)

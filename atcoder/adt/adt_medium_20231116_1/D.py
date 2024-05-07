a,b,c,d,e,f = map(int,input().split())
mod = 998244353
ans = a*b*c
ans %= mod
ans -= d*e*f
ans %= mod
print(ans)

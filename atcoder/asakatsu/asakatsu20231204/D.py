import sys
sys.setrecursionlimit(10**7)

a,b,k = map(int, input().split())


def f(x,y):
    n = x + y
    z = min(x,y)
    par = 1
    for i in range(n-z+1, n+1):
        par *= i
    ch = 1
    for i in range(2,z+1):
        ch *= i
    return par//ch

ans = ""
n = a+b
now = 0
for i in range(n):
    if a>0:
        temp = f(a-1,b)
        if now+temp<k:
            ans += 'b'
            now += temp
            b -= 1
        else:
            ans += 'a'
            a -= 1
    else:
        ans += 'b'
        b -= 1

print(ans)
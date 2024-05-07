import io
import sys
_INPUT = """\
5 4 7
8 3 10 5 13



"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

n,k,x=map(int,input().split())
a = list(map(int, input().split()))

a.sort()
a.reverse()

for i in range(n):
    if k==0:
        break
    if k >= a[i]//x:
        k -= a[i]//x
        a[i] %= x

a.sort()
a.reverse()
for i in range(n):
    if k==0:
        break
    if k:
        a[i] = max(0, a[i]-x)
        k -= 1

print(sum(a))
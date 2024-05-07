import io
import sys
_INPUT = """\
11 2

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

n,k=map(int,input().split())
ans = 0
while n>0:
    n //= k
    ans += 1

print(ans)
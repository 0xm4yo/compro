import io
import sys
_INPUT = """\
2
1 2



"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

n = int(input())
a = list(map(int, input().split()))

b = [0]*(n*2+10)
b[0] = 0
for i in range(0, n):
    b[i*2+1] = b[a[i]-1]+1
    b[i*2+2] = b[a[i]-1]+1

for i in range(0, 2*n+1):
    print(b[i])

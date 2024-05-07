import io
import sys
_INPUT = """\
3 3
0 1 0
1 0 1
0 0 0

"""
sys.stdin = io.StringIO(_INPUT)

# Anser

N, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
MOD = 10 ** 9 + 7

def matrix_multiply(x, y):
    I = len(x)
    J = len(y[0])
    K = len(y)
    Z = [[0] * J for _ in range(I)]
    for i in range(I):
        for j in range(J):
            for k in range(K):
                Z[i][j] += x[i][k] * y[k][j]
                Z[i][j] %= MOD
    return Z

def matrix_pow(x, n):
    y = [[0] * len(x) for _ in range(len(x))]

    for i in range(len(x)):
        y[i][i] = 1
    
    while n:
        if n & 1:
            y = matrix_multiply(y, x)
        x = matrix_multiply(x, x)
        n >>= 1
    
    return y

temp = matrix_pow(A, K)
ans = 0
for t in temp:
    ans += sum(t)
    ans %= MOD

print(ans)
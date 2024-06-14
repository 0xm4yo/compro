n = int(input())
A = list(map(int,input().split()))
B = list(input().split())
dp = [[[[0]*5 for _ in range(34)] for __ in range(10)] for ___ in range(n+1)]

dp[0][0][0][0] = 1
m = 998244353
arr = []
for i in range(n):
    arr.append((B[i],A[i]))

arr.sort()
ans = 0
for i in range(n):
    a = arr[i][1]
    b = arr[i][0]
    b1 = b
    b2 = ''
    if b[-1]=='X':
        if b == 'X':
            b1 = 0
            b2 = 'X'
        else:
            b1 = int(b[:-1])
            b2 = 'X'
    b1 = int(b1)
    for j in range(9):
        for k in range(34):
            for l in range(5):
                if dp[i][j][k][l] == 0:
                    continue
                dp[i+1][j][k][l] += dp[i][j][k][l] % m
                if l + a >= 5:
                    continue
                if k + b1 >= 34:
                    continue
                if j == 8:
                    if k + b1 != 33:
                        continue
                    if l + a != 4:
                        continue
                    if l + a < k:
                        if b2 == 'X' and b1 == 0:
                            ans += dp[i][j][k][l]
                            ans %= m
                    else:
                        if b2 == 'X':
                            # ans += dp[i][j][k][l]
                            ans %= m
                else:
                    if b2 == 'X':
                        continue
                    dp[i+1][j+1][k+b1][l+a] += dp[i][j][k][l] % m

print(ans)
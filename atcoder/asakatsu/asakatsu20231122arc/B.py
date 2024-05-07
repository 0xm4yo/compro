import math
n = int(input())
x = list(map(int, input().split()))

v = [True]*60
for i in range(2,50):
    if not v[i]:
        continue
    p = i + i
    while p<50:
        v[p] = False
        p += i
        

arr = []
for i in range(2,50):
    if v[i]:
        arr.append(i)

m = len(arr)
ans = 100000000000000000000000000000
for i in range(1, 1<<m):
    temp = 1
    for j in range(m):
        if i&(1<<j):
            temp *= arr[j]
    flag = True
    for j in range(n):
        if math.gcd(temp,x[j])==1:
            flag = False
    if flag:
        ans = min(ans, temp)
print(ans)


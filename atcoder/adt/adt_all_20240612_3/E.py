n = int(input())
a = list(map(int,input().split()))
cum = [0]
for i in range(n):
    cum.append(cum[-1]+a[i])

mi = min(cum[1:])
if mi > 0:
    mi = 0
print(cum[-1]-mi)
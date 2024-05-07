import sys
sys.setrecursionlimit(10**5)
from collections import defaultdict

mod = [86018120556494023, 605727305799004993, 15975524077365773, 124289485833216689, 1863834829003362973, 13105660438060880077]
n = int(input())
a = [int(input()) for _ in range(n)]

for m in mod:
    d = defaultdict(int)
    b = [0]*n
    flag = False
    for i in range(n):
        for j in range(1,11):
            if (a[i]-j!=0 and (a[i]-j)%m==0):
                flag = True
        b[i] = a[i]%m
    if (flag):
        continue

    for bb in b:
        d[bb] += 1

    ans = 0
    for i in range(n):
        for j in range(n):
            ans += d[b[i]*b[j]%m]
    print(ans)
    exit()

print(0)
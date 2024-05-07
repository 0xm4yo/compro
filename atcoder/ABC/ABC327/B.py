import sys
sys.setrecursionlimit(10**5)
b = int(input())
for i in range(1,20):
    p = pow(i,i)
    if (p>1000000000000000000):
        break
    if (p==b):
        print(i)
        exit()

print(-1)

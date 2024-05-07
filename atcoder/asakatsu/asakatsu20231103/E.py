import sys
sys.setrecursionlimit(10**5)

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
q = int(input())

sa = set()
sb = set()
ah = [0]*n
bh = [0]*n
mod = 9999999999999937
for i in range(n):
    if (a[i] not in sa):
        sa.add(a[i])
        ah[i] = a[i]*(a[i]*12854271+51851452)*(a[i]*31742646+511616)%mod
    if (b[i] not in sb):
        sb.add(b[i])
        bh[i] = b[i]*(b[i]*12854271+51851452)*(b[i]*31742646+511616)%mod

am = [0]*(n+1)
bm = [0]*(n+1)
for i in range(n):
    am[i+1]=am[i]+ah[i]
    am[i+1]%=mod
    bm[i+1]=bm[i]+bh[i]
    bm[i+1]%=mod

while q:
    q -= 1
    x,y=map(int,input().split())
    if(am[x]==bm[y]):
        print("Yes")
    else:
        print("No")

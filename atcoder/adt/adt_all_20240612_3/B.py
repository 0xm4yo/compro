n,p,q,r,s=map(int,input().split())
a = list(map(int,input().split()))
for i in range(1,n+1):
    if p<=i and i<=q:
        print(a[r+i-p-1])
    elif r<=i and i<=s:
        print(a[p+i-r-1])
    else:
        print(a[i-1])
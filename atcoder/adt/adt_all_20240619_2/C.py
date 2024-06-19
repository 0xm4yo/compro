a,m,l,r = map(int,input().split())
a -= m * (10**18)
cntl = (l-a)//m
cntr = (r-a)//m
off = 0
if (l-a)%m==0:
    off = 1
print(cntr-cntl+off)
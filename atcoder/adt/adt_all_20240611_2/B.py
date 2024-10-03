n,m,x,t,d = map(int,input().split())

if x <= m:
    print(t)
    exit()

t0 = t - x*d
print(t0 + m*d)
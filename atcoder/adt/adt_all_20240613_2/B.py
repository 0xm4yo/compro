a = list(map(int,input().split()))
b = list(map(int,input().split()))
s = sum(a)
t = sum(b)

if t > s:
    print(0)
else:
    print(s-t+1)
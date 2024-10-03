r,c = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(2)]
r -= 1
c -= 1
print(a[r][c])
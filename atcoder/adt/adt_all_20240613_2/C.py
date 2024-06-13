n = int(input())
arr = []
for i in range(n+1):
    for j in range(n+1):
        for k in range(n+1):
            if (i+j+k<=n):
                arr.append((i,j,k))
arr.sort()
for a in arr:
    print(*a)
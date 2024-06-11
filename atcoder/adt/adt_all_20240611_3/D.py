t = int(input())
while t:
    n = int(input())
    a = list(map(int,input().split()))
    cnt = 0
    for aa in a:
        if aa%2:
            cnt += 1
    print(cnt)
    t -= 1
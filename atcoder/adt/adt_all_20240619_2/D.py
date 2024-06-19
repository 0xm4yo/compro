k,g,m = map(int,input().split())
nowg = 0
nowm = 0
while k:
    if nowg == g:
        nowg = 0
    else:
        if nowm == 0:
            nowm = m
        else:
            rem = g - nowg
            if rem > nowm:
                nowg += nowm
                nowm = 0
            else:
                nowg = g
                nowm -= rem                
    k -= 1
print(nowg, nowm)
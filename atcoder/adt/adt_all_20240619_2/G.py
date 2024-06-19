a,b,c = map(int,input().split())
cnt0 = 0
cnt1 = 0
for i in range(60):
    if c&(1<<i):
        cnt1 += 1
    else:
        cnt0 += 1
assert cnt1 + cnt0 == 60

if cnt1 > a + b:
    print(-1)
    exit()

for i in range(cnt1+1):
    aa = a - i
    bb = b - (cnt1-i)
    if aa == bb and aa <= cnt0:
        ansa = 0
        ansb = 0
        cnt = i
        for j in range(60):
            if (c&(1<<j)) and cnt:
                ansa += 1<<j
                cnt -= 1
        for j in range(60):
            if (c&(1<<j)) and (ansa&(1<<j))==0:
                ansb += 1<<j
        assert ansa + ansb == c
        cnt = aa
        for j in range(60):
            if (c&(1<<j)==0) and cnt:
                ansa += 1<<j
                ansb += 1<<j
                cnt -= 1
        
        print(ansa, ansb)
        exit()

print(-1)

n = int(input())
s = [input() for _ in range(n)]

cnt = 0
for ss in s:
    if ss == 'For':
        cnt += 1

if (n-cnt) < cnt:
    print('Yes')
else:
    print('No')
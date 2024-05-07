S = list(input().split())
n = int(input())
ng = [input() for _ in range(n)]

for s in S:
    sz = len(s)
    flag = False
    for t in ng:
        if (len(t)!=sz):
            continue
        flag2 = True
        for j in range(sz):
            if s[j] != t[j]:
                if (t[j]!='*'):
                    flag2 = False
        if flag2:
            flag = True
    if flag:
        ans = ""
        for j in range(sz):
            ans += '*'
        print(ans)
    else:
        print(s)
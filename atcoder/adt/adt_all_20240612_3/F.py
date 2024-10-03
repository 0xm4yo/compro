h,w = map(int, input().split())
s = [input() for _ in range(h)]

ans = [['.']*w for _ in range(h)]
for i in range(h):
    for j in range(w):
        if ans[i][j] == 'C':
            continue
        if j+1 < w and s[i][j]=='T' and s[i][j+1]=='T':
            ans[i][j] = 'P'
            ans[i][j+1] = 'C'
        else:
            ans[i][j] = s[i][j]

for i in range(h):
    for j in range(w):
        print(ans[i][j], end="")
    print()

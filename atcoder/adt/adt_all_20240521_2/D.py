s = input()
n = len(s)
ans = 0
for i in range(n):
    for j in range(1,n+1):
        if i+j>n: continue
        t = s[i:j+i]
        t2 = ""
        for k in range(len(t)):
            t2 += t[len(t)-k-1]
        # print(t, t2)
        if (t==t2):
            ans = max(ans, j)
print(ans)
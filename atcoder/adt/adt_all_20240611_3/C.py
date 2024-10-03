n = int(input())
s = [input() for _ in range(n)]

ans = 0
for i in range(n):
    for j in range(n):
        for k in range(-1,2):
            for l in range(-1,2):
                if k==0 and l==0:
                    continue
                t = ""
                for d in range(n):
                    t += s[(i+k*d)%n][(j+l*d)%n]
                ans = max(ans, int(t))
print(ans) 
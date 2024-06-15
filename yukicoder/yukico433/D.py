a = [input() for _ in range(6)]
v = [False] * 1000000
for i in range(1, 11**6):
    x = [0] * 6
    for j in range(6):
        cnt = (i // (11 ** j)) % 11
        for k in range(6):
            x[k] += (ord(a[j][k]) - ord('0')) * cnt
            x[k] %= 10
    off = 1
    now = 0
    for j in range(6):
        now += x[j] * off
        off *= 10
    v[now] = True

print(v.count(True))
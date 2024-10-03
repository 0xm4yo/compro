n = int(input())
a = list(map(int,input().split()))
ev = []
od = []
for aa in a:
    if aa%2:
        od.append(aa)
    else:
        ev.append(aa)

ev.sort()
od.sort()
ans = -1
if len(ev)>=2:
    ans = max(ans, ev[-1] + ev[-2])
if len(od)>=2:
    ans = max(ans, od[-1] + od[-2])
print(ans)
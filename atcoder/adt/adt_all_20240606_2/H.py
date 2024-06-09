m = 29138390677831739179
c = 58135780
d = 95782391535

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
q = int(input())

arra = [0]
arrb = [0]
from collections import defaultdict
da = defaultdict(int)
db = defaultdict(int)

for i in range(n):
    if a[i] not in da:
        da[a[i]] += 1
        arra.append((arra[-1]+(d+a[i])*(c+a[i]))%m)
    else:
        arra.append((arra[-1]))

    if b[i] not in db:
        db[b[i]] += 1    
        arrb.append((arrb[-1]+(d+b[i])*(c+b[i]))%m)
    else:
        arrb.append((arrb[-1]))

for i in range(q):
    x, y = map(int, input().split())
    if (arra[x] == arrb[y]):
        print("Yes")
    else:
        print("No")


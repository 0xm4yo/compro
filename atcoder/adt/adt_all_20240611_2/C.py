n = int(input())
flag = True

from collections import defaultdict
d = defaultdict(int)

s = [""] * n
t = [""] * n
for i in range(n):
    s[i], t[i] = input().split()
    d[s[i]] += 1
    if s[i]==t[i]:
        continue
    d[t[i]] += 1

for i in range(n):
    if (d[s[i]] > 1 and d[t[i]] > 1):
        flag = False

if flag:
    print("Yes")
else:
    print("No")
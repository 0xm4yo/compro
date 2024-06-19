n,m = map(int,input().split())
s = list(input().split())
t = list(input().split())
from collections import defaultdict
d = defaultdict(int)
for tt in t:
    d[tt] = 1
for ss in s:
    if d[ss]:
        print('Yes')
    else:
        print('No')
n, k = map(int, input().split())
a = list(map(int, input().split()))

cnt = [0] * 100010
for aa in a:
    cnt[aa] += 1

for i in range(1,100010):
    if cnt[i] + cnt[0] >= k:
        print('Yes')
        exit(0)
print('No')
n, k= map(int,input().split())
a = list(map(int, input().split()))

l = 0
r = 100000000000
while r-l>1:
    mid = (l+r)//2
    cnt = 0
    for aa in a:
        if aa <= mid:
            cnt += 1
    if cnt <= k:
        l = mid
    else:
        r = mid

arr = [1] * n
for i in range(n):
    if a[i] <= l:
        arr[i] = 0

# print(arr)
ans = []
for i in range(1,n):
    if arr[i-1]==0 and arr[i]==1:
        ans.append(i+1)
print(len(ans))
print(*ans)
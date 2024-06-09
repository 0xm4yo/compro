n = int(input())
arr = [1,6,30,180,360,720]
arr.reverse()
s = ['C', 'M', 'S', 'R', 'o', '.']

ans = ""
for i in range(6):
    if n // arr[i] == 0:
        continue
    cnt = n // arr[i]
    for j in range(cnt):
        ans += s[i]
    n %= arr[i]
print(ans)
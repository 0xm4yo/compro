n = int(input())
s = input()
ans = []
for i in range(n-1):
    if s[i]=='x' and s[i+1] == 'o':
        ans.append(i+2)
print(len(ans))
print(*ans)
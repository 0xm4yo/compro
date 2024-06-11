n = int(input())
s = input()

for i in range(1,n):
    for j in range(n):
        if j+i>=n:
            print(j)
            break
        if s[j] == s[j+i]:
            print(j)
            break

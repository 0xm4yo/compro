n = int(input())
s = input()
arr = [False] * 3
for i in range(n):
    arr[ord(s[i])-ord('A')] = True
    if False not in arr:
        print(i+1)
        exit()
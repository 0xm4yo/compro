s = input()

if (s[0:3]=='ABC'):
    n = int(s[3:6])
    if 1<=n<=315 or 317 <= n <= 349:
        print("Yes")
        exit()
print("No")
b = int(input())
for i in range(1,100000):
    if (i**i > 10**18):
        break
    if (i**i == b):
        print(i)
        exit()
print(-1)
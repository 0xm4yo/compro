n = int(input())
w = list(input().split())

for ww in w:
    if ww in [ "and", "not", "that", "the", "you"]:
        print("Yes")
        exit()
print('No')
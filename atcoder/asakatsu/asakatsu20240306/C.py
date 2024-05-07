x = int(input())

for a in range(-3000,3001):
    for b in range(-3000,3001):
        if (a*a*a*a*a-b*b*b*b*b==x):
            print(a)
            print(b)
            exit()

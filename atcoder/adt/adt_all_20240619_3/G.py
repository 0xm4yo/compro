s = input()
q = int(input())
n = len(s)
a = 'ABC'
while q:
    q -= 1
    t, k = map(int,input().split())
    arr = []
    k -= 1
    while t and k:
        arr.append(k%2)
        k //= 2
        t -= 1
    arr.reverse()
    if k == 0:
        b = (a.index(s[0]) + t) % 3
        for x in arr:
            if x:
                b -= 1
                b %= 3
            else:
                b += 1
                b %= 3
    elif t == 0:
        b = a.index(s[k])
        for x in arr:
            if x:
                b -= 1
                b %= 3
            else:
                b += 1
                b %= 3
    print(a[b])


    
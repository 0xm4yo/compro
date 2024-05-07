y,m,d = map(int,input().split('/'))
m -= 1
d -= 1
arr = [31,28,31,30,31,30,31,31,30,31,30,31]
# print(sum(arr))
while(1):
    if y%4 or (y%100==0 and y%400):
        arr[1] = 28
        if (y%((m+1)*(d+1))==0):
            ans = ""
            ans += str(y)
            ans += '/'
            if (m+1<10):
                ans += '0'
            ans += str(m+1)
            ans += '/'
            if (d+1<10):
                ans += '0'
            ans += str(d+1)
            print(ans)
            exit()
        d += 1
        if (d==arr[m]):
            d = 0
            m += 1
            if (m==12):
                m = 0
                y += 1
    else:
        arr[1] = 29
        if (y%((m+1)*(d+1))==0):
            ans = ""
            ans += str(y)
            ans += '/'
            if (m+1<10):
                ans += '0'
            ans += str(m+1)
            ans += '/'
            if (d+1<10):
                ans += '0'
            ans += str(d+1)
            print(ans)
            exit()

        d += 1
        if (d==arr[m]):
            d = 0
            m += 1
            if (m==12):
                m = 0
                y += 1
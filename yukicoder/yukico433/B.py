n = int(input())
arr = [0,0]
for i in range(2,n+2):
    arr.append(2**i-1)
a = 1
for i in range(2,n+1):
    a *= arr[i]
b = arr[-1]
if a%b:
    print('No')
else:
    print('Yes')
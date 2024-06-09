n = int(input())

if n==0:
    print('#')
    exit()

init = [['#']*3 for _ in range(3)]
init[1][1] = '.'

def f(k):
    if k == 1:
        return init
    
    pre = f(k-1)
    sz = len(pre)*3
    arr = [['.']*sz for _ in range(sz)]
    for i in range(sz):
        for j in range(sz):
            if i%(3**(k-1)) or j%(3**(k-1)):
                continue
            if i==3**(k-1) and j==3**(k-1):
                continue
            for a in range(len(pre)):
                for b in range(len(pre)):
                    arr[i+a][j+b] = pre[a][b]
    return arr

ans = f(n)

for i in range(len(ans)):
    for j in range(len(ans)):
        print(ans[i][j], end="")
    print()
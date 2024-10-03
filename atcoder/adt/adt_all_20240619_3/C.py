h,w = map(int,input().split())
s = [input() for _ in range(h)]

t = 'snuke'

for i in range(h):
    for j in range(w):
        for dh in range(-1,2):
            for dw in range(-1,2):
                if dh == 0 and dw == 0:
                    continue
                cnt = 0
                temp = True
                for k in range(5):
                    if not (0 <= i+dh*k < h):
                        temp = False
                        break
                    if not (0 <= j+dw*k < w):
                        temp = False
                        break
                    if s[i+dh*k][j+dw*k] != t[k]:
                        temp = False
                        break
                if temp:
                    for k in range(5):
                        print(i+dh*k+1, j+dw*k+1)
                    exit()

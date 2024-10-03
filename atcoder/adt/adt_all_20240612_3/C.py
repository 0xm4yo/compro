s = [input() for _ in range(8)]
for i in range(8):
    for j in range(8):
        if s[i][j]=='*':
            t = chr(ord('a')+j)
            print(f'{t}{8-i}')
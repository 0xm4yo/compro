import io
import sys
_INPUT = """\
1101110101


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

s = input()

if (s[0]=='1'):
    print("No")
    exit()


arr = [[6], [3], [1,7], [0, 4], [8, 2], [5], [9]]
for i in range(0, len(arr)):
    flag = False
    for a in arr[i]:
        if (s[a]=='1'):
            flag = True
    if flag==False:
        continue
    flag = False
    pos = i+1
    for j in range(pos, len(arr)):
        flag2 = False
        for b in arr[j]:
            if (s[b]=='1'):
                flag2 = True
        if flag2==False:
            flag = True
            pos = j
            break
    if flag==False:
        continue
    flag = False
    for j in range(pos, len(arr)):
        for b in arr[j]:
            if (s[b]=='1'):
                print("Yes")
                exit()
print("No")
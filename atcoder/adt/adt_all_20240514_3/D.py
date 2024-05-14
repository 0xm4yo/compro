n = int(input())
s = []
for i in range(n):
    ss = input()
    s.append(ss)

c1 = [ "H" , "D" , "C" , "S" ]
c2 = ["A" , "2" ,"3" , "4" , "5" , "6" , "7" , "8" , "9" , "T" , "J" , "Q" , "K" ]

flag = True
for ss in s:
    if ss[0] not in c1:
        flag = False
    if ss[1] not in c2:
        flag = False
    


for i in range(n):
    for j in range(i+1,n):
        if s[i]==s[j]:
            flag = False

if flag:
    print("Yes")
else:
    print("No")

x1,y1,x2,y2 = map(int,input().split())
st1 = set()
st2 = set()

for i in range(-2,3):
    for j in range(-2,3):
        if i*i + j*j == 5:
            st1.add((x1+i,y1+j))
            st2.add((x2+i,y2+j))

for a in st1:
    if a in st2:
        print('Yes')
        exit()
print('No')
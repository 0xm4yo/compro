n = int(input())
st = set()
for i in range(1,2*n+2):
    st.add(i)

while 1:
    arr = list(st)
    print(arr[0])
    st.remove(arr[0])
    b = int(input())
    if b == 0:
        break
    st.remove(b)

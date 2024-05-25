s = input()
st = set()

for i in range(1, 316):
    st.add("ABC"+f"{i:03d}")
for i in range(317, 350):
    st.add("ABC"+f"{i:03d}")
# print(st)
if s in st:
    print("Yes")
else:
    print("No")

n = int(input())
la = [input() for _ in range(n)]

st = set()
for a in la:
    st.add(a)
print(len(st))

# st = [set() for _ in range(200100)]
# mod = 9999999999999937

# for i in range(n):
#     temp = 0
#     for a in la[i][1:]:
#         temp += a
#         temp *= a*1233 + 144167
#         temp %= mod
#         temp *= a*4161 + 490432
#         temp %= mod
#     st[la[i][0]].add(temp)

# ans = 0
# for s in st:
#     ans += len(s)
# print(ans)




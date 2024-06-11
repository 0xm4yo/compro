s = input()
y = int(s[-1])

ans = s[:-2]
if 0 <= y <= 2:
    ans += '-'
elif 7 <= y <= 9:
    ans += '+'
print(ans)
    
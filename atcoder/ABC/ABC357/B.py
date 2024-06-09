s = input()

n = len(s)
cnt = 0
for ss in s:
    if 0 <= ord(ss)-ord('a') < 26:
        cnt += 1
if n-cnt < cnt:
    print(s.lower())
else:
    print(s.upper())
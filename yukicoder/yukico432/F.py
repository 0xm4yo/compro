n = int(input())
s = input()
cnt = [0] * 26
for ss in s:
    cnt[ord(ss)-ord('A')] += 1
if max(cnt) > 1:
    print('Yes')
else:
    print('No')
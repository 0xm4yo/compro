n = int(input())

l = 1
r = n+1
while r-l>1:
    mid = (l+r)//2
    print(f'? {mid}')
    x = int(input())
    if x:
        r = mid
    else:
        l = mid
print(f'! {l}')
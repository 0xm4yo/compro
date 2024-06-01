N, M = map(int, input().split())

MOD = 998244353
ans = 0

for i in range(60):
    if (M & (1 << i)) != 0:
        bit = ((N + 1) // (1 << (i + 1))) * (1 << i)
        remainder = (N + 1) % (1 << (i + 1))
        if remainder > (1 << i):
            bit += remainder - (1 << i)
        ans += bit
        ans %= MOD

print(ans)
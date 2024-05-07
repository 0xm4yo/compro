def eratosthenes(N):
    isprime = [True] * (N + 1)
    isprime[0] = isprime[1] = False
    p = 2
    while p * p <= N:
        if isprime[p]:
            q = p * p
            while q <= N:
                isprime[q] = False
                q += p
        p += 1
    return isprime

def main():
    n = int(input())

    arr = eratosthenes(1000000)
    p = [i for i in range(1000000) if arr[i]]
    m = len(p)
    ans = 0

    for i in range(m):
        a = p[i]
        if a * a > n:
            break
        for j in range(i + 1, m):
            b = p[j]
            if a * a * b > n:
                break
            for k in range(j + 1, m):
                c = p[k]
                if a * a * b * c * c > n:
                    break
                else:
                    ans += 1

    print(ans)

if __name__ == "__main__":
    main()
# https://www.codechef.com/problems/ICPC16E
import sys
MOD = int(1e9 + 7)

def bin_pow(a, b):
    res = 1
    a %= MOD
    while b:
        if b % 2:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b //= 2
    return res

t = int(sys.stdin.readline())

while t:
    t -= 1
    n, c = [int(i) for i in sys.stdin.readline().split()]

    # Exponentes
    g0 = (5 * n * n) % (MOD - 1)
    g1 = ((5 * n * n + 3 * (1 if n % 2 else 0)) // 4) % (MOD - 1)
    g2 = (5 * n * n // 2 + (1 if n % 2 else 0)) % (MOD - 1)

    ans = 0
    ans = (ans + bin_pow(c, g0)) % MOD
    ans = (ans + bin_pow(c, g1)) % MOD
    ans = (ans + bin_pow(c, g2)) % MOD
    ans = (ans + bin_pow(c, g1)) % MOD
    ans = (ans * bin_pow(4, MOD - 2)) % MOD

    sys.stdout.write(str(ans) + "\n")
    
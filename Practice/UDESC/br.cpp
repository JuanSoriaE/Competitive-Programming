#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MOD 1000000007

long long binpow(long long a, long long b) {
    long long res = 1;

    while (b) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

long long modInverse(long long x) {
    return binpow(x, MOD - 2);
}

vector<long long> berlekampMassey(vector<long long> s) {
    vector<long long> C(1, 1), B(1, 1);

    int L = 0, m = 1;
    long long b = 1;

    for (int n = 0; n < s.size(); n++) {
        long long d = 0;

        for (int i = 0; i <= L; i++)
            d = (d + C[i] * s[n - i]) % MOD;

        if (d == 0) {
            m++;
            continue;
        }

        vector<long long> T = C;

        long long coef = d * modInverse(b) % MOD;

        if (C.size() < B.size() + m)
            C.resize(B.size() + m);

        for (int i = 0; i < B.size(); i++) {
            C[i + m] =
                (C[i + m] - coef * B[i]) % MOD;
        }

        if (2 * L <= n) {
            L = n + 1 - L;
            B = T;
            b = d;
            m = 1;
        } else {
            m++;
        }
    }

    C.erase(C.begin());

    for (auto &x : C)
        x = (MOD - x) % MOD;

    return C;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    vector<ll> seq = {1,1,2,3,5,8};
    auto res = berlekampMassey(seq);
    for (ll &i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}
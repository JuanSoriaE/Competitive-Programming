#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MOD = 998244353;
constexpr int MAX_K = 200000;

ll inv[MAX_K];

ll bin_pow(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll C(ll n, int k) {
    ll res = 1;
    for (ll i = 1; i <= k; i++)
        res = ((res * ((n - k + i) % MOD) % MOD) * inv[i]) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k; cin >> n >> k;

    for (int i = 1; i < k; i++)
        inv[i] = bin_pow(i, MOD - 2);

    ll k_inv = bin_pow(k, MOD - 2), len = 1, ans = 0;
    for (int i = 0; i <= n; i++) {
        ll aux = (MOD + 1LL - (C(len + k - 1, k - 1) * k_inv) % MOD) % MOD;
        ans = (ans + aux) % MOD;

        k_inv = (k_inv * k_inv) % MOD;
        len = (2LL * len) % MOD;
    }
    cout << ans << '\n';

    return 0;
}
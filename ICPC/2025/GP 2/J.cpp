#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

#define MOD 998244353

#define MAX_N 1000002
ll f[MAX_N];

ll bin_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return bin_pow(a, MOD - 2);
}

ll C(ll n, ll k) {
    if (n < k) return 0;
    return (((f[n] * inv(f[k])) % MOD) * inv(f[n - k])) % MOD;
}

void solve() {
    ll n, k; cin >> n >> k;
    cout << C(n + 1, k + 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    f[0] = 1;
    for (ll i = 1; i < MAX_N; i++)
        f[i] = (f[i - 1] * i) % MOD;
    int q; cin >> q;
    while (q--) solve();
    return 0;
}
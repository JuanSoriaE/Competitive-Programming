#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll unsigned long long
#define ld long double

#define MOD 1000000007

#define MAX_N 1000000

ll fact[MAX_N + 1];

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

ll c(ll n, ll x) {
    if (x > n) return 0;
    return (fact[n] * bin_pow((fact[x] * fact[n - x]) % MOD, MOD - 2)) % MOD;
}

void solve() {
    int n; cin >> n;
    int evens = n / 2, odds = n - evens;
    ll ans = (c(evens, 3) + (evens * c(odds, 2)) % MOD) % MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    fact[0] = fact[1] = 1;
    for (int i = 1; i <= MAX_N; i++)
        fact[i] = (i * fact[i - 1]) % MOD;

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
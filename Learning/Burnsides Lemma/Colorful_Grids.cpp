// https://www.codechef.com/problems/ICPC16E
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define lli long long int
#define ld long double
#define uset unordered_set
#define umap unordered_map
#define MOD 1000000007

ll bin_pow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    lli n, c; cin >> n >> c;
    // Exponentes
    lli g0 = (5 * n * n) % (MOD - 1);
    lli g1 = ((5 * n * n + 3 * (n % 2)) / 4) % (MOD - 1);
    lli g2 = (5 * n * n / 2 + (n % 2)) % (MOD - 1);
    debug(g0);
    debug(g1);
    debug(g2);

    lli ans = 0;
    ans = (ans + bin_pow(c, g0)) % MOD;
    debug(ans);
    ans = (ans + bin_pow(c, g1)) % MOD;
    debug(ans);
    ans = (ans + bin_pow(c, g2)) % MOD;
    debug(ans);
    ans = (ans + bin_pow(c, g1)) % MOD;
    debug(ans);
    cout << ((ans * bin_pow(4, MOD - 2)) % MOD) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
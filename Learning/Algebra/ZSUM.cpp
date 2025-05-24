// https://www.spoj.com/submit/ZSUM/
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

#define MOD 10000007

ll bin_pow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll solve(ll &n, ll &k) {
    ll ans = 0;
    ans = (ans + (2 * bin_pow(n - 1, n - 1)) % MOD) % MOD;
    ans = (ans + (2 * bin_pow(n - 1, k)) % MOD) % MOD;
    ans = (ans + bin_pow(n, n)) % MOD;
    ans = (ans + bin_pow(n, k)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll n, k;
    while (1) {
        cin >> n >> k;
        if (n == 0) return 0;
        cout << solve(n, k) << "\n";
    }

    return 0;
}
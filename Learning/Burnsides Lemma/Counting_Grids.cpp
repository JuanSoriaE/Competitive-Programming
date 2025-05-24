// https://cses.fi/problemset/task/2210/
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
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll n; cin >> n;
    // Exponentes
    ll g0 = n * n;
    ll g1 = (n * n + 3 * (n % 2)) / 4;
    ll g2 = n * n / 2 + (n % 2);

    ll ans = 0;
    ans = (ans + bin_pow(2, g0)) % MOD;
    ans = (ans + bin_pow(2, g1)) % MOD;
    ans = (ans + bin_pow(2, g2)) % MOD;
    ans = (ans + bin_pow(2, g1)) % MOD;
    cout << ((ans * bin_pow(4, MOD - 2)) % MOD) << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ull unsigned long long
#define ld long double

const int MOD = 1e9 + 7;

ull ans = 1;

ull bin_pow(ull a, int b) {
    ull res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;

        b >>= 1;
    }
    return res;
}

ull inv(ull a) {
    return bin_pow(a, MOD - 2);
}

ull nume(ull a) {
    return (3 * (((a * a) % MOD) + ((2 * a) % MOD) + (a & 1)) % MOD) % MOD;
}

void solve() {
    ull n; cin >> n;
    ull num = nume(n - 2);
    ull den = (inv(2) * ((((inv(n) * inv(n - 1)) % MOD) * inv(n - 2)) % MOD)) % MOD;

    ull res = (num * den) % MOD;
    ans = (ans * res) % MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MOD = 1000000007;

ll bin_pow(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> X(q);
    for (int &i : X) cin >> i;

    ll a = bin_pow(2, MOD - 2); // 1/2
    vector<ll> suffix(q + 1);
    for (int i = q - 1; i >= 0; i--)
        suffix[i] = (((suffix[i + 1] + X[i]) % MOD) * a) % MOD;

    vector<ll> ans(n + 1); ans[1] = suffix[0];
    for (int i = 0; i < q; i++) {
        int x = X[i];
        ans[x] = (ans[x] + (a * suffix[i + 1]) % MOD) % MOD;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';

    return 0;
}
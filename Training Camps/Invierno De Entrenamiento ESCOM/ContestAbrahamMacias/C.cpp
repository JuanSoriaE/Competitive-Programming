#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define ll long long

ll bin_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res % MOD;
}

int main() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<ll> cnt(10, 0);
    for (int i = 0; i < n; i++) cnt[a[i] - '0']++;
    for (int i = 0; i < m; i++) cnt[b[i] - '0']++;

    if (m > n) swap(n, m);

    ll res = 0;
    ll j = 1;
    for (ll exp = 0; exp < n; exp++) {
        while (cnt[j] == 0) j++;

        ll mult = bin_pow(10, exp);
        if (exp < m) {
            res = (res + (j * mult) % MOD) % MOD;
            cnt[j]--;
        }
        while (cnt[j] == 0) j++;
        
        res = (res + (j * mult) % MOD) % MOD;
        cnt[j]--;
    }

    cout << res % MOD << "\n";

    return 0;
}
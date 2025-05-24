#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool solve() {
    int n; cin >> n;
    vector<ll> v(n);
    ll mn = LLONG_MAX;
    int mn_cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < mn) {
            mn = v[i];
            mn_cnt = 1;
        } else if (v[i] == mn)
            mn_cnt++;
    }

    if (mn_cnt > 1) return true;

    bool mn_flag = false;
    ll _gcd = -1;
    for (ll &a : v) {
        if (mn == a || a % mn) continue;

        _gcd = _gcd == -1 ? a : gcd(_gcd, a);
    }

    return mn == _gcd;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}
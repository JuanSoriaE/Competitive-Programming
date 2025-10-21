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

void solve() {
    int n, q; cin >> n >> q;
    map<ll, ll> mp;
    int prev_x; cin >> prev_x;
    ll open = n - 1; mp[open]++;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        mp[open] += static_cast<ll>(x) - prev_x - 1;
        open += n - 1 - i;
        mp[open]++;
        open -= i;
        prev_x = x;
    }

    while (q--) {
        ll k; cin >> k;
        cout << (mp.count(k) ? mp[k] : 0) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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
#define rep(i, s, n) for (int i = s; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<ll> prefix_sum(n);
    ll cur = 0, aux;
    rep(i, 0, n) {
        cin >> aux;
        cur += aux;
        prefix_sum[i] = cur;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        ll range_sum = prefix_sum[r] - (l == 0 ? 0 : prefix_sum[l - 1]);
        ll m = r - l + 1;
        cout << (range_sum == m * (m + 1) / 2 ? "TAK" : "NIE") << "\n";
    }

    return 0;
}
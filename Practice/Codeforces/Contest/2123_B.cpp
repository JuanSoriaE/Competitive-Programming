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
    int n, j, k; cin >> n >> j >> k;
    j--;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    int eliminated = (mx == v[j] ? 0 : -1);
    for (int i = 0; i < n; i++) {
        if (i == j) continue;
        eliminated += (v[i] <= mx);
    }

    cout << (eliminated >= (n - k) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
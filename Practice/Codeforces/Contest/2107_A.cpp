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

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    rep(i, 0, n) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    bool equal = 1;
    rep(i, 1, n) equal &= v[i - 1] == v[i];

    if (equal) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    rep(i, 0, n)
    cout << (v[i] == mx ? 1 : 2) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> prefix(n), suffix(n);
    prefix[0] = v[0]; suffix[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++) {
        prefix[i] = min(prefix[i - 1], v[i]);
        suffix[n - 1 - i] = max(suffix[n - i], v[n - 1 - i]);
    }

    for (int i = 0; i < n; i++)
        cout << (prefix[i] == v[i] || suffix[i] == v[i] ? 1 : 0);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
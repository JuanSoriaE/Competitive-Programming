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
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mn = min(mn, a);
        mx = max(mx, a);
    }

    int x; cin >> x;
    cout << ((mn <= x && x <= mx) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
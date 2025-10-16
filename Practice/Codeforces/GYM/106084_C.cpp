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

#define MAX_N 200000
ll dp[MAX_N + 1];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) dp[i] = 0;

    for (int i = 0; i < m; i++) {
        int x, y; ll v; cin >> x >> y >> v;
        swap(dp[x], dp[y]);
        dp[x] += v;
        dp[y] += v;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
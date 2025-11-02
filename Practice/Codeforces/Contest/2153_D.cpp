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
int a[MAX_N];
ll dp[MAX_N];

int cost(int x, int y, int z) {
    if (y < x) swap(y, x);
    if (z < x) swap(z, x);
    if (z < y) swap(z, y);

    return z - x;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = LLONG_MAX;
    for (int c = 0; c < 4; c++) {
        dp[0] = LLONG_MAX - 2e9;
        dp[1] = abs(a[0] - a[1]);
        dp[2] = cost(a[0], a[1], a[2]);

        for (int i = 3; i < n; i++)
            dp[i] = min(dp[i - 2] + abs(a[i] - a[i - 1]),
                        dp[i - 3] + cost(a[i], a[i - 1], a[i - 2]));
        ans = min(ans, dp[n - 1]);

        for (int i = n - 2; i >= 0; i--) swap(a[i], a[i + 1]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
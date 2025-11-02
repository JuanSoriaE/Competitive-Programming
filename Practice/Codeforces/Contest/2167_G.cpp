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

#define MAX_N 8000
int a[MAX_N], cost[MAX_N];
ll dp[MAX_N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        total += cost[i];
        dp[i] = cost[i];
    }

    for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
    if (a[j] <= a[i])
        dp[i] = max(dp[i], dp[j] + cost[i]);

    ll mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, dp[i]);

    cout << (total - mx) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
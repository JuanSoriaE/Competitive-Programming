#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 300000

int n;
pair<ll, int> a[MAX_N];
ll dp[MAX_N + 1];

ll dfs(int i, ll diff) {
    if (dp[i] != 0)
        return dp[i];

    dp[i] = diff;

    auto l = lower_bound(a, a + n - 1, make_pair(diff, 0));
    auto r = upper_bound(a, a + n - 1, make_pair(diff, INT_MAX));
    for (auto it = l; it != r; it++)
        dp[i] = max(dp[i], dfs(it->second, diff + it->second - 1));

    return dp[i];
}

void solve() {
    cin >> n;
    fill(dp, dp + n + 1, 0);

    ll aux; cin >> aux;
    for (int i = 2; i <= n; i++) {
        cin >> aux;
        a[i - 2] = {aux - (n - i + 1), i};
    }
    sort(a, a + n - 1);

    cout << dfs(0, 0) + n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> a, b, dp;
int n;

ll dfs(int i, ll a_sum, ll b_sum) {
    if (i == n)
        return abs(a_sum - b_sum);

    if (dp[i] != -1) return dp[i];

    dp[i] = min(
        dfs(i + 1, a_sum + a[i], b_sum),
        dfs(i + 1, a_sum, b_sum + b[i])
    );

    return dp[i];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    a.resize(n); b.resize(n); dp.resize(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    dfs(0, 0, 0);
    cout << dp[0] << "\n";

    return 0;
}
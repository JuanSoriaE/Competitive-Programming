#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 5000;

int prefix_a[MAX_N + 1], prefix_b[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];

void solve() {
    string a, b; cin >> a >> b;
    int n = sz(a), m = sz(b);

    for (int i = 0; i < n; i++)
        prefix_a[i + 1] = (prefix_a[i] + (a[i] - '0')) % 10;
    for (int i = 0; i < m; i++)
        prefix_b[i + 1] = (prefix_b[i] + (b[i] - '0')) % 10;

    if (prefix_a[n] != prefix_b[m]) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (prefix_a[i - 1] == prefix_b[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

    cout << dp[n][m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
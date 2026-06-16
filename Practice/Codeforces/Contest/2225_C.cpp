#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 200000

string grid[2];
int dp[MAX_N + 1];

void solve() {
    int n; cin >> n;
    cin >> grid[0] >> grid[1];
    dp[n] = 0; dp[n - 1] = grid[0][n - 1] != grid[1][n - 1];
    for (int i = n - 2; i >= 0; i--)
        dp[i] = min(
            dp[i + 1] + (grid[0][i] != grid[1][i]),
            dp[i + 2] + (grid[0][i] != grid[0][i + 1]) +
                        (grid[1][i] != grid[1][i + 1])
        );
    cout << dp[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
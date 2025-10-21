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

const vector<pair<int, int>> OFFS = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

int n, m;

bool in_bound(int r, int c) {
    return min(r, c) >= 0 && r < n && c < m;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> dp(n, vector<int>(m, 1));
    for (char c = 65; c <= 90; c++) {
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            for (auto &[x, y] : OFFS) {
                if (in_bound(i + x, j + y) && grid[i][j] == grid[i + x][j + y] + 1)
                    dp[i][j] = max(dp[i][j], dp[i + x][j + y] + 1);
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        ans = max(ans, dp[i][j]);

    cout << ans << '\n';

    return 0;
}
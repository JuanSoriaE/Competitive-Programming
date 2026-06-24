#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    for (string &s : mat) cin >> s;

    vector<vector<int>> dp_rgt(n, vector<int>(m, 1));
    vector<vector<int>> dp_top(n, vector<int>(m, 1));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--) {
        dp_rgt[i][j] += (j == m || mat[i][j + 1] != mat[i][j]) ? 0 : dp_rgt[i][j + 1];
        dp_top[i][j] += (i == 0 || mat[i - 1][j] != mat[i][j]) ? 0 : dp_top[i - 1][j];

        ans += (dp_rgt[i][j] - 1) * (dp_top[i][j] - 1);
    }
    cout << ans << '\n';

    return 0;
}
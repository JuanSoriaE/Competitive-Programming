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

#define MAX_N 50
#define MAX_M 50
char grid[MAX_N][MAX_M];
bool vst[MAX_N][MAX_M];
const vector<pair<int, int>> OFFS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;

bool is_valid(int r, int c) {
    return min(r, c) >= 0 && r < n && c < m;
}

void BFS() {
    queue<pair<int, int>> q;
    if (grid[n - 1][m - 1] == '.')
        q.push({n - 1, m - 1}), vst[n - 1][m - 1] = true;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (auto &[x, y] : OFFS) {
            int new_r = r + x, new_c = c + y;
            if (!is_valid(new_r, new_c) ||
                grid[new_r][new_c] == '#' || vst[new_r][new_c])
                continue;

            vst[new_r][new_c] = true;
            q.push({new_r, new_c});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
        cin >> grid[r][c], vst[r][c] = false;

    for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
    if (grid[r][c] == 'B')
        for (auto &[x, y] : OFFS)
        if (is_valid(r + x, c + y) && grid[r + x][c + y] == '.')
            grid[r + x][c + y] = '#';

    BFS();

    for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
    if ((grid[r][c] == 'B' && vst[r][c]) ||
        (grid[r][c] == 'G' && !vst[r][c])) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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

vector<vector<bool>> grid; // 1: wall
const vector<pair<int, int>> DIRS = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
vector<vector<int>> vst; // 0: unvisited, 1: visited: once, 2: visited twice
int N, M;
int max_depth, r_start, c_start, nodes;

void dfs(const int r, const int c, int depth, const int &vst_limit) {
    if (vst[r][c] == vst_limit) return;

    vst[r][c] = vst_limit;
    nodes++;
    if (depth >= max_depth) {
        max_depth = depth;
        r_start = r; c_start = c;
    }

    for (const auto &[x, y] : DIRS) {
        int new_r = r + x, new_c = c + y;
        if (min(new_r, new_c) < 0 || new_r >= N || new_c >= M || grid[new_r][new_c]) continue;

        dfs(new_r, new_c, depth + 1, vst_limit);
    }
}

void solve(int t) {
    cin >> N >> M;
    grid.assign(N, vector<bool>(M));
    string s;
    for (int r = 0; r < N; r++) {
        cin >> s;
        for (int c = 0; c < M; c++) 
            grid[r][c] = s[c] == '#';
    }

    vst.assign(N, vector<int>(M, 0));   
    int regions = 0, largest_region = 0, min_dist = 0;
    for (int r = 0; r < N; r++)
    for (int c = 0; c < M; c++) {
        if (grid[r][c] || vst[r][c] > 0) continue;

        regions++;
        max_depth = 0;
        dfs(r, c, 0, 1);
        nodes = 0;
        dfs(r_start, c_start, 0, 2);

        if (nodes > largest_region) {
            largest_region = nodes;
            min_dist = max_depth;
        } else if (nodes == largest_region) {
            min_dist = max(min_dist, max_depth);
        }
    }
    cout << "Case " << t << ": " << regions << " " << largest_region << " " << min_dist << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve(i + 1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;

string mat[MAX_N];
bool vst[MAX_N][MAX_M];

pair<int, int> OFFS[8] = {{-1, -1}, {-1, 0}, {-1 ,1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int n, m, ans = 0;

bool is_valid(int i, int j) {
    return min(i, j) >= 0 && i < n && j < m;
}

void dfs(int i, int j) {
    if (vst[i][j]) return;
    vst[i][j] = true;

    for (auto &[x, y] : OFFS) {
        int new_i = i + x, new_j = j + y;
        if (!is_valid(new_i, new_j) ||
            vst[new_i][new_j] ||
            mat[new_i][new_j] != mat[i][j]) continue;

        dfs(new_i, new_j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (vst[i][j] || mat[i][j] == '0') continue;
        dfs(i, j);
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
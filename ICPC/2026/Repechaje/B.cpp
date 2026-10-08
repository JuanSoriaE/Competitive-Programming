#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 750;
constexpr ll INF = LLONG_MAX;

ll mat[MAX_N][MAX_N], inc[MAX_N + 1][MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        cin >> mat[i][j];
        if (mat[i][j] == -1) mat[i][j] = INF;
    }

    int m; cin >> m;
    while (m--) {
        int x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;
        int tmp_x = x1, tmp_y = y1;

        x1--, y1--, x2--, y2--;
        for (int i = min(x1, x2); i <= max(x1, x2); i++)
            inc[i][min(y1, y2)] += k,
            inc[i][max(y1, y2) + 1] -= k;
    }

    for (int i = 0; i < n; i++) {
        ll cur = 0;
        for (int j = 0; j < n; j++) {
            cur += inc[i][j];
            if (mat[i][j] != INF && i != j)
                mat[i][j] += cur;
        }
    }

    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    if (mat[i][k] < INF && mat[k][j] < INF)
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--, b--;
        cout << (mat[a][b] == INF ? -1 : mat[a][b]) << '\n';
    }

    return 0;
}
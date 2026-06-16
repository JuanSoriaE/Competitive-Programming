#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 50
#define MAX_M 50

bool grid[MAX_N][MAX_M];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, total = 0; cin >> n >> m;

    for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++) {
        bool a; cin >> a;
        grid[r][c] = a;
        if (a) total++;
    }

    int ans = 0;
    while (total) {
        ans++;
        int r = 0, c = 0;
        while (r < n) {
            if (grid[r][c]) {
                grid[r][c] = false;
                total--;
            }

            bool remaining_at_r = false;
            for (int i = c + 1; i < m && !remaining_at_r; i++)
                remaining_at_r = grid[r][i];

            if (remaining_at_r) c++;
            else r++;
        }
    }
    cout << ans << '\n';

    return 0;
}
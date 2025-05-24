#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int r = 0; r < n; r++) {
        cin >> grid[r];
        for (int c = 0; c < m && grid[r][c] == '1'; c++)
            grid[r][c] = 'V';
    }

    for (int c = 0; c < m; c++)
    for (int r = 0;
        r < n && (grid[r][c] == 'V' || grid[r][c] == '1');
        r++)
        grid[r][c] = 'V';

    for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
        if (grid[r][c] == '1')
        return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}
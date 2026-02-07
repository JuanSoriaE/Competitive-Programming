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

#define MAX_N 1000
#define MAX_M 1000
int mat[MAX_N][MAX_M];
int n, m;

bool is_valid(int r, int c) {
    return min(r, c) >= 0 && r < n && c < m;
}

void solve() {
    cin >> n >> m;
    int cur = 1;
    for (int i = 0; i < m; i++) {
        int r = 0, c = i;
        while (is_valid(r, c)) {
            mat[r][c] = cur++;
            r++, c--;
        }
    }

    for (int i = 1; i < n; i++) {
        int r = i, c = m - 1;
        while (is_valid(r, c)) {
            mat[r][c] = cur++;
            r++, c--;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 10000

short p[MAX_N + 1];
short prefix[MAX_N + 1][MAX_N + 1];

short query(int l, int r, int v) {
    return prefix[r][v] - prefix[l - 1][v];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix[i][p[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        short row_prefix = 0;
        for (int j = 1; j <= n; j++) {
            row_prefix += prefix[i][j];
            prefix[i][j] = row_prefix + (i ? prefix[i - 1][j] : 0);
        }
    }

    while (m--) {
        int l, r, x; cin >> l >> r >> x;
        int smaller = query(l, r, p[x] - 1);
        cout << (smaller == x - l ? "Yes" : "No") << '\n';
    }

    return 0;
}
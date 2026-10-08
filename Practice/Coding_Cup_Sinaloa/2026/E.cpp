#pragma GCC optimized ("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;

int rects[MAX_N][4];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<vector<int>> rects(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++) cin >> rects[i][j];

    sort(all(rects));

    while (q--) {
        int x, y, ans = 0; cin >> x >> y;
        for (int i = 0; i < n; i++) {
            if (rects[i][0] > x) break;
            if (rects[i][0] <= x && x <= rects[i][2] && rects[i][1] <= y && y <= rects[i][3])
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
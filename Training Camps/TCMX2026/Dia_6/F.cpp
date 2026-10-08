#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 4000;

struct DSU {
    vector<int> p;
    DSU(int n) : p(n) {
        iota(all(p), 0);
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[p[a]]); }
    void erase(int a) { p[a] = find(a + 1); }
};

pair<int, int> pairs_x[2 * MAX_N], pairs_y[2 * MAX_N];
bool colors[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    // x1, y1, x2, y2, c
    vector<array<int, 5>> posters(n);
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        auto &[x1, y1, x2, y2, c] = posters[i];
        cin >> x1 >> y1 >> x2 >> y2 >> c;

        pairs_x[j++] = {x1, i}; pairs_x[j++] = {x2, -(i + 1)};
        pairs_y[k++] = {y1, i}; pairs_y[k++] = {y2, -(i + 1)};
    }

    sort(pairs_x, pairs_x + 2 * n);
    sort(pairs_y, pairs_y + 2 * n);

    int nxt_x = 0, nxt_y = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i && pairs_x[i - 1].first != pairs_x[i].first)
            nxt_x++;
        if (pairs_x[i].second >= 0) // x1
            posters[pairs_x[i].second][0] = nxt_x;
        else
            posters[-pairs_x[i].second - 1][2] = nxt_x;

        if (i && pairs_y[i - 1].first != pairs_y[i].first)
            nxt_y++;
        if (pairs_y[i].second >= 0) // y1
            posters[pairs_y[i].second][1] = nxt_y;
        else
            posters[-pairs_y[i].second - 1][3] = nxt_y;
    }

    vector<DSU> rows(nxt_y + 1, DSU(nxt_x + 2));
    for (int i = n - 1; i >= 0; i--) {
        auto &[x1, y1, x2, y2, c] = posters[i];
        for (int row = y2; row < y1; row++) {
            int x = rows[row].find(x1);
            while (x < x2) {
                colors[c] = true;
                rows[row].erase(x);
                x = rows[row].find(x);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    ans += colors[i];

    cout << ans << '\n';

    return 0;
}
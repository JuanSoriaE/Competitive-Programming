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

#define MAX_N 100000
vector<pair<int, int>> intervals[MAX_N];
bool possible[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, d; cin >> n >> d;
    fill(possible, possible + n + 1, true);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (intervals[a].empty() || i - intervals[a].back().second >= d)
            intervals[a].push_back({i, i});
        else
            intervals[a].back().second = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(intervals[i]); j++) {
            auto [l, r] = intervals[i][j];
            if (r - l + 1 > d ||
                (j && l - intervals[i][j - 1].second - 1 < d)) {
                possible[i] = false;
                break;
            }

            int op1_l = (j ? intervals[i][j - 1].second + d + 1 : 0);
            int op2_l = r - d + 1;
            int new_l = max(op1_l, op2_l);

            intervals[i][j] = {new_l, new_l + d - 1};
        }
    }

    int ans = -1;
    for (int i = 0; i <= n && ans == -1; i++)
    if (possible[i]) ans = i;
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;

int a[MAX_N + 1];

bool overlap(pair<int, int> &a, pair<int, int> &b) {
    return min(a.second, b.second) >= max(a.first, b.first);
}

pair<bool, pair<int, int>> dfs(int u, vector<vector<int>> &children) {
    if (sz(children[u]) == 0)
        return {true, {a[u], a[u]}};

    const int m = sz(children[u]);
    vector<pair<int, int>> intervals(m);
    int j = 0;
    for (int &v : children[u]) {
        auto child = dfs(v, children);
        if (!child.first)
            return {false, {0, 0}};

        intervals[j++] = child.second;
    }

    int dec_cnt = 0, dec_start;
    for (int i = 1; i < m; i++) {
        if (overlap(intervals[i], intervals[i - 1]))
            return {false, {0, 0}};

        if (intervals[i] < intervals[i - 1])
            dec_cnt++, dec_start = i;
    }

    if (dec_cnt == 0)
        return {true, {intervals[0].first, intervals[m - 1].second}};
    if (dec_cnt > 1)
        return {false, {0, 0}};

    int start = (dec_start + 1) % m;
    for (int i = start, j = 0; j < m - 1; i = (i + 1) % m, j++) {
        int prev = i ? i - 1 : m - 1;

        if (overlap(intervals[i], intervals[prev]) ||
            intervals[i] < intervals[prev])
            return {false, {0, 0}};
    }

    return {true, {intervals[dec_start].first, intervals[dec_start - 1].second}};
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        children[p].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << (dfs(1, children).first ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
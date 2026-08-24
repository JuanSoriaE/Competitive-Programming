#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

pair<int, int> dfs(int u, int idx, int y, vector<vector<array<int, 3>>> &adj, vector<bool> &vst) {
    pair<int, int> res = {idx, y};
    for (auto &[v, i, y] : adj[u]) {
        if (!vst[v]) {
            vst[v] = true;
            res = dfs(v, i, y, adj, vst);
        }
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<array<int, 4>> edges(n);
    vector<pair<int, int>> pairs(2 * n);
    for (int i = 0; i < n; i++) {
        auto &[u, v, x, y] = edges[i];
        cin >> u >> v;
        x = u, y = v;
        pairs[2 * i] = {u, i + 1};
        pairs[2 * i + 1] = {v, -(i + 1)};
    }

    sort(all(pairs));

    int nxt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i && pairs[i].first != pairs[i - 1].first)
            nxt++;
        int j = pairs[i].second;
        if (j > 0)
            edges[j - 1][0] = nxt;
        else
            edges[-j - 1][1] = nxt;
    }

    vector<vector<array<int, 3>>> adj(nxt + 1);
    for (int i = 0; i < n; i++) {
        auto &[u, v, x, y] = edges[i];
        adj[u].push_back({v, i, y});
        adj[v].push_back({u, i, x});
    }

    vector<bool> vst(nxt + 1);
    vector<pair<int, int>> res;
    for (int i = 0; i < nxt; i++)
    if (!vst[i])
        res.push_back(dfs(i, -1, -1, adj, vst));

    cout << sz(res) - 1 << '\n';
    if (sz(res) == 1) return;

    for (int i = 1; i < sz(res); i++) {
        auto &[j, c] = res[i];
        cout << j + 1 << " " << c << " " << res[0].second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
// https://codeforces.com/gym/102694/problem/D
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 300000;
constexpr int LOG = 19;

vector<pair<int, int>> adj[MAX_N + 1];

int up[MAX_N + 1][LOG + 1], mini[MAX_N + 1][LOG + 1], depth[MAX_N + 1];

void dfs(int u = 1, int p = 0, int w = 0) {
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    mini[u][0] = w;
    for (int i = 1; i <= LOG; i++)
        up[u][i] = up[up[u][i - 1]][i - 1],
        mini[u][i] = min(mini[u][i - 1], mini[up[u][i - 1]][i - 1]);
    for (auto &[v, w] : adj[u])
    if (v != p) dfs(v, u, w);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int i = 0; i <= LOG; i++)
    if (k & (1 << i)) u = up[u][i];
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--)
    if (up[u][i] != up[v][i])
        u = up[u][i], v = up[v][i];
    return up[u][0];
}

int kth_ancestor_mini(int u, int k) {
    int res = INT_MAX;
    for (int i = 0; i <= LOG; i++)
    if (k & (1 << i))
        res = min(res, mini[u][i]),
        u = up[u][i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs();

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        int l = lca(a, b);
        cout << min(
            kth_ancestor_mini(a, depth[a] - depth[l]),
            kth_ancestor_mini(b, depth[b] - depth[l])
        ) << '\n';
    }

    return 0;
}
// https://judge.yosupo.jp/problem/jump_on_tree
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 500000;
constexpr int LOG = 19;

vector<int> adj[MAX_N];
int up[MAX_N][LOG + 1], depth[MAX_N];

void dfs(int u = 0, int p = 0) {
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for (int i = 1; i <= LOG; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int &v : adj[u])
    if (v != p) dfs(v, u);
}

int kth_ancestor(int u, int k) {
    for (int i = 0; i <= LOG; i++)
    if (k & (1 << i)) u = up[u][i];
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = kth_ancestor(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--)
    if (up[u][i] != up[v][i])
        u = up[u][i], v = up[v][i];
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    while (q--) {
        int s, t, i; cin >> s >> t >> i;
        int l = lca(s, t);
        int ds = depth[s] - depth[l], dt = depth[t] - depth[l];
        int d = ds + dt;
        if (i > d) {
            cout << "-1\n";
            continue;
        }

        cout << (i <= ds ? kth_ancestor(s, i) : kth_ancestor(t, d - i)) << '\n';
    }

    return 0;
}
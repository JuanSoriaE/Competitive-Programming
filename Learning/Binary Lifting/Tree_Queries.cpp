// https://codeforces.com/contest/1328/problem/E
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
constexpr int LOG = 18;

vector<int> adj[MAX_N + 1];

int depth[MAX_N + 1], up[MAX_N + 1][LOG + 1];

void dfs(int u = 1, int p = 0) {
    depth[u] = depth[p] + 1;
    up[u][0] = p;

    for (int i = 1; i <= LOG; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int &v : adj[u])
    if (v != p) dfs(v, u);
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

string solve() {
    int k; cin >> k;
    vector<int> v(k);
    int deepest = 0;
    for (int &u : v) {
        cin >> u;
        if (depth[u] > depth[deepest])
            deepest = u;
    }

    for (int &u : v) {
        int _lca = lca(deepest, u);
        if (depth[u] - depth[_lca] > 1)
            return "NO";
    }

    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[0] = -1;
    dfs();

    while (m--) cout << solve() << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 1000000;
constexpr int MAX_M = 1000000;

vector<pair<int, int>> adj[MAX_N];

int low[MAX_N], discovered[MAX_N];
bool vst[MAX_N], bridge[MAX_M];

int timer = 1;
void dfs(int u, int p = -1) {
    low[u] = discovered[u] = timer++;
    vst[u] = true;

    for (auto &[v, i] : adj[u]) {
        if (v == p) continue;
        if (!discovered[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (discovered[u] < low[v]) bridge[i] = true;
        } else {
            low[u] = min(low[u], discovered[v]);
        }
    }
}

int p[MAX_N], _size[MAX_N];

int find(int a) { return a == p[a] ? a : p[a] = find(p[p[a]]); }
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;

    if (_size[a] > _size[b]) swap(a, b);
    p[a] = b;
    _size[b] += _size[a];
}

vector<int> t_adj[MAX_N];

pair<int, int> diameter(int u, int p = -1, int cur_d = 0) {
    vst[u] = true;
    pair<int, int> res = {cur_d, u};
    for (int &v : t_adj[u])
    if (v != p)
        res = max(res, diameter(v, u, cur_d + 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges[i] = {u, v};
    }

    int components = 0;
    for (int u = 0; u < n; u++)
    if (!vst[u])
        components++, dfs(u);

    iota(p, p + n, 0);
    fill(_size, _size + n, 1);

    for (int i = 0; i < m; i++)
    if (!bridge[i])
        unite(edges[i].first, edges[i].second);

    for (int i = 0; i < m; i++)
    if (bridge[i]) {
        int u = find(edges[i].first), v = find(edges[i].second);
        t_adj[u].push_back(v);
        t_adj[v].push_back(u);
    }

    fill(vst, vst + n, false);

    int ans = 0;
    for (int u = 0; u < n; u++)
    if (!vst[u])
        ans += diameter(diameter(u).second).first;

    cout << ans + components - 1 << '\n';

    return 0;
}
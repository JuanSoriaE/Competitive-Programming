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

struct DSU {
    vector<int> p, size;
    DSU(int n) : p(n), size(n, 1) { iota(all(p), 0); }
    int find(int a) { return (p[a] == a ? a : (p[a] = find(p[a]))); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        return 1;
    }
    int get_size(int a) {
        return size[find(a)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    vector<int> e(n + 1);
    for (int u = 1; u <= n; u++) {
        int _e; cin >> _e;
        mp[_e].push_back(u);
        e[u] = _e;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DSU dsu(n + 1);
    vector<int> ans(n + 1);
    for (auto [_e, nodes] : mp) {
        for (int u : nodes)
        for (int v : adj[u])
        if (e[v] <= _e) dsu.unite(u, v);

        for (int u : nodes)
        ans[u] = dsu.get_size(u);
    }

    for (int u = 1; u <= n; u++)
    cout << ans[u] << "\n";

    return 0;
}
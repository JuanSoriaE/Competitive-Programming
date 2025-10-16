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
    vector<int> p, size, mn, mx;
    DSU(int n) : p(n), size(n, 1), mn(n), mx(n) { for (int i = 0; i < n; i++) { p[i] = i; mn[i] = INT_MAX; mx[i] = INT_MIN; } }
    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b, int w) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        mn[b] = min(w, min(mn[b], mn[a]));
        mx[b] = max(w, max(mx[b], mx[a]));
        return 1;
    }
    pair<int, int> getMinMax(int a) {
        return {mn[find(a)], mx[find(a)]};
    }
};

void solve() {
    int n, m; cin >> n >> m;
    int u, v, w;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(all(edges));
    
    DSU dsu(n + 1);
    int res = INT_MAX;
    for (auto edge : edges) {
        int w = edge[0], u = edge[1], v = edge[2];
        dsu.unite(u, v, w);
        if (dsu.find(1) == dsu.find(n)) {
            auto [mn, mx] = dsu.getMinMax(1);
            res = min(res, mn + mx);
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
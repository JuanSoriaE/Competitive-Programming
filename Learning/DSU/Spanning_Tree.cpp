// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E
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
    int find(int a) { return p[a] == a ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;
        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        return 1;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};


int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int w, u, v; cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }

    sort(all(edges));
    DSU dsu(n + 1);

    ll weight = 0;
    for (const auto &[w, u, v] : edges) {
        if (dsu.same_set(u, v)) continue;
        dsu.unite(u, v);
        weight += (ll)w;
    }
    cout << weight << "\n";

    return 0;
}
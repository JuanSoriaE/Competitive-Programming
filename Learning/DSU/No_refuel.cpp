// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/G
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

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

struct DSU {
    vector<int> p, size;
    int sets;
    DSU(int n) : p(n), size(n, 1) { iota(all(p), 0); sets = n; }
    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;
        sets--;
        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        return 1;
    }
};


int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<Edge> es(m);
    for (int i = 0; i < m; i++) {
        cin >> es[i].u >> es[i].v >> es[i].w;
        es[i].u--; es[i].v--;
    }
    sort(all(es));
    DSU dsu(n);
    int i = 0;
    while (dsu.sets > 1) {
        dsu.unite(es[i].u, es[i].v);
        i++;
    }
    cout << (i == 0 ? es[0].w : es[i - 1].w) << "\n";
    return 0;
}
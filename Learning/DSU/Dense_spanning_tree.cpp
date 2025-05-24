// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/F
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
    int u, v;
    ll w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

struct DSU {
    vector<int> p, size;
    int sets;
    DSU(int n) : p(n), size(n, 1) { iota(all(p), 0); sets = n; }
    int find(int a) { return p[a] == a ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        sets--;
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
    vector<Edge> es(m);
    for (int i = 0; i < m; i++) {
        cin >> es[i].u >> es[i].v >> es[i].w;
        es[i].u--; es[i].v--;
    }
    sort(all(es));

    ll ans = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        DSU dsu(n);
        int j = i;
        while (dsu.sets > 1 && j < m) {
            dsu.unite(es[j].u, es[j].v);
            j++;
        }

        if (dsu.sets == 1)
            ans = min(ans, es[j - 1].w - es[i].w);
    }

    cout << (ans == LLONG_MAX ? "NO" : "YES") << "\n";
    if (ans != LLONG_MAX)
        cout << ans << "\n";
    return 0;
}
// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/H
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
    int u, v, i;
    ll w;
    bool operator<(const Edge &other) const { return w > other.w; }
};
std::ostream& operator<<(std::ostream& os, const Edge& e) {
    os << "(" << e.u << "," << e.v << "," << e.w << "," << e.i << ")";
    return os;
}

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

template <typename T>
void print_v(const vector<T>& v) {
    for (int i = 0; i < sz(v); i++)
        cout << v[i] << "\n";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    ll s; cin >> s;
    vector<Edge> edges(m);
    int u, v;
    ll w, total_w = 0;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].i = i;
    }
    sort(all(edges));

    ll skipped_cost = 0;
    vector<Edge> skipped_edges;
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++) {
        if (dsu.same_set(edges[i].u, edges[i].v)) {
            skipped_cost += edges[i].w;
            skipped_edges.push_back(edges[i]);
        } else {
            dsu.unite(edges[i].u, edges[i].v);
        }
    }

    int i = 0;
    while (skipped_cost > s)
        skipped_cost -= skipped_edges[i++].w;
    
    vector<int> ans;
    for (; i < sz(skipped_edges); i++)
        ans.push_back(skipped_edges[i].i + 1);
    sort(all(ans));

    cout << sz(ans) << "\n";
    for (i = 0; i < sz(ans); i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}
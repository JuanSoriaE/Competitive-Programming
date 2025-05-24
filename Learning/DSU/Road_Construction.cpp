// https://cses.fi/problemset/task/1676
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
    int largest, sets;
    DSU(int n) : p(n + 1), size(n + 1, 1), largest(1), sets(n) { iota(all(p), 0); }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        sets--;
        largest = max(largest, size[b]);
        return 1;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    DSU dsu(n);
    int u, v;
    int cities = n;
    while (m--) {
        cin >> u >> v;
        dsu.unite(u, v);
        cout << dsu.sets << " " << dsu.largest << "\n";
    }
    return 0;
}
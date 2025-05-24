// https://codeforces.com/contest/25/problem/D
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

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
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
    int n; cin >> n;
    DSU dsu(n + 1);
    int u, v;
    vector<pair<int, int>> unnecessary;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        if (dsu.find(u) == dsu.find(v)) unnecessary.push_back({u, v});
        else dsu.unite(u, v);
    }

    vector<int> necessary;
    for (int u = 2; u <= n; u++) {
        if (dsu.find(u) == dsu.find(1)) continue;
        necessary.push_back(u);
        dsu.unite(u, 1);
    }

    cout << sz(unnecessary) << "\n";
    for (int i = 0; i < sz(unnecessary); i++)
        cout << unnecessary[i].first << " " << unnecessary[i].second << " " << necessary[i] << " " << 1 << "\n";

    return 0;
}
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
#define rep(i, s, n) for (int i = s; i < n; i++)
#define pii pair<int, int>

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
        return 0;
    }
};

int solve() {
    int n; cin >> n;
    vector<int> w;
    vector<pii> sorted;
    int aux;
    rep(i, 0, n) {
        cin >> aux;
        if (w.empty() || w.back() != aux) w.push_back(aux);
    }
    n = sz(w);
    rep(i, 0, n) sorted.push_back({w[i], i});
    sort(all(sorted), greater<pii>());

    DSU dsu(n);
    int clones = 0;
    for (const auto &[x, i] : sorted) {
        if (dsu.find(i) == i) clones++;
        if (i > 0) dsu.unite(i - 1, i);
        if (i < n - 1) dsu.unite(i + 1, i);
    }
    return clones;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
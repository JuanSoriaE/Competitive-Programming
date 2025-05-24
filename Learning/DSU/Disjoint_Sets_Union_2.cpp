// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
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
    vector<pair<int, int>> data; // min, max
    DSU(int n) : p(n + 1), size(n + 1, 1), data(n + 1) { iota(all(p), 0); for (int i = 1; i <= n; i++) data[i] = {i, i}; }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];

        data[b].first = min(data[b].first, data[a].first);
        data[b].second = max(data[b].second, data[a].second);
        return 1;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    DSU dsu(n);
    string s;
    int u, v;
    while (q--) {
        cin >> s;
        if (s == "union") {
            cin >> u >> v;
            dsu.unite(u, v);
            continue;
        }

        cin >> u;
        int p = dsu.find(u);
        cout << dsu.data[p].first << " " << dsu.data[p].second << " " << dsu.size[p] << "\n";
    }
    return 0;
}
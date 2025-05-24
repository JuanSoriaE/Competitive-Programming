// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
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
    set<int> unconnected;
    DSU(int n) : p(n), size(n, 1) { iota(all(p), 0); for (int i = 0; i < n; i++) unconnected.insert(i); }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        return 1;
    }
    void unite_range(int x, int y) {
        int a = *unconnected.lower_bound(x);
        while (a < y) {
            unite(a, a + 1);
            unconnected.erase(a);
            a = *unconnected.lower_bound(a);
        }
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    DSU dsu(n + 1);
    int t, x, y;
    while (q--) {
        cin >> t >> x >> y;
        if (t == 1) dsu.unite(x, y);
        else if (t == 2) dsu.unite_range(x, y);
        else cout << (dsu.same_set(x, y) ? "YES" : "NO") << "\n";
    }
    return 0;
}
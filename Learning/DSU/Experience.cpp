// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
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
    vector<int> p, size, exp;
    DSU(int n) : p(n + 1), size(n + 1, 1), exp(n + 1, 0) { iota(all(p), 0); }

    int find(int a) { return a == p[a] ? a : find(p[a]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];

        exp[a] -= exp[b];
        return 1;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
    void add_exp(int a, int v) { exp[find(a)] += v; }
    int get_exp(int a) {
        if (p[a] == a) return exp[a];
        return exp[a] + get_exp(p[a]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    string t;
    int u, v;
    DSU dsu(n);
    while (q--) {
        cin >> t;
        if (t == "join") {
            cin >> u >> v;
            dsu.unite(u, v);
        } else if (t == "add") {
            cin >> u >> v;
            dsu.add_exp(u, v);
        } else {
            cin >> u;
            cout << dsu.get_exp(u) << "\n";
        }
    }
    return 0;
}
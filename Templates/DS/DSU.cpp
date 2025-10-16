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

// Disjoint Set Union

// DSU with path compression
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

// DSU for bipartition test
struct DSU {
    vector<int> p, size, len;
    DSU(int n) : p(n), size(n, 1), len(n, 0) { iota(all(p), 0); }

    pair<int, int> find(int a) {
        if (a == p[a]) return {a, 0};
        const auto [pa, la] = find(p[a]);
        p[a] = pa;
        len[a] = (len[a] + la) % 2;
        return {p[a], len[a]};
    }
    bool unite(int a, int b) {
        auto [pa, la] = find(a);
        auto [pb, lb] = find(b);
        if (pa == pb) return 0;

        if (size[pa] > size[pb]) { swap(pa, pb); swap(la, lb); }
        p[pa] = pb;
        size[pb] += size[pa];
        len[pa] = (la + lb + 1) % 2;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
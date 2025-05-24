// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/J
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
#define fst first
#define snd second

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
    
        if (size[pa] > size[pb]) {
            swap(pa, pb);
            swap(la, lb);
        }
        p[pa] = pb;
        size[pb] += size[pa];
        len[pa] = (la + lb + 1) % 2;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    DSU dsu(n + 1);
    int i = 0, u, v, _m = m;
    while (_m--) {
        cin >> u >> v;
        dsu.unite(u, v);
        if (dsu.find(u).snd == dsu.find(v).snd)
            break;
        i++;
    }
    cout << (i == m ? -1 : i + 1) << "\n";
    return 0;
}
// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/I
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
    DSU dsu(n);
    int t, a, b, shift = 0, x, y;
    while (m--) {
        cin >> t >> a >> b;
        x = (a + shift) % n; y = (b + shift) % n;
        if (t) {
            int lx = dsu.find(x).snd,
                ly = dsu.find(y).snd;
            
            if (lx == ly) shift = (shift + 1) % n;
            cout << (lx == ly ? "YES" : "NO") << "\n";
        } else {
            dsu.unite(x, y);
        }
    }
    return 0;
}
// https://www.spoj.com/problems/CLFLARR/
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
    vector<int> p, size, end;
    DSU(int n) : p(n), size(n, 1), end(n) { iota(all(p), 0); iota(all(end), 0); }
    int find(int a) { return p[a] == a ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        end[b] = max(end[b], end[a]);
        return 1;
    }
    int get_end(int a) { return end[find(a)]; }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<array<int, 3>> querys(q);
    for (int i = 0; i < q; i++) {
        int l, r, c; cin >> l >> r >> c;
        querys[i] = {--l, --r, c};
    }

    vector<int> arr(n);
    DSU dsu(n + 1);

    reverse(all(querys));
    for (const auto &[l, r, c] : querys)
    for (int i = dsu.get_end(l); i <= r; i = dsu.get_end(i)) {
        arr[i] = c;
        dsu.unite(i, i + 1);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";

    return 0;
}
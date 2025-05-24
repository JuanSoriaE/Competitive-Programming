// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
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
    vector<int> p, size, mx;
    DSU(int n) : p(n), size(n, 1), mx(n) { iota(all(p), 0); for (int i = 0; i < n; i++) mx[i] = i; }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        mx[b] = max(mx[a], mx[b]);
        return 1;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
    int get_max(int a) { return mx[find(a)]; }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    DSU dsu(n + 2);

    char s; int x;
    while (q--) {
        cin >> s >> x;

        if (s == '-') dsu.unite(x, x + 1);
        else {
            int mx = dsu.get_max(x);
            cout << (mx == n + 1 ? -1 : mx) << "\n";
        }
    }

    return 0;
}
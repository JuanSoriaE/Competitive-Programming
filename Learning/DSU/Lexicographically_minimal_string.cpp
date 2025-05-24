// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406
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
    vector<int> p, size, mn;
    DSU(int n) : p(n), size(n, 1), mn(n) { iota(all(p), 0); for (int i = 0; i < n; i++) mn[i] = i; }
    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        mn[b] = min(mn[b], mn[a]);
        return 1;
    }
    int get_min(int a) { return mn[find(a)]; }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string a, b, c; cin >> a >> b >> c;
    DSU dsu(26);
    for (int i = 0; i < sz(a); i++)
        dsu.unite(a[i] - 'a', b[i] - 'a');

    for (int i = 0; i < sz(c); i++)
        c[i] = dsu.get_min(c[i] - 'a') + 'a';

    cout << c << "\n";
    return 0;
}
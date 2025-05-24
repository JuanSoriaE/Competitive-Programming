// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B
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
    DSU(int n) : p(n), size(n, 1) { iota(all(p), 0); }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    int unite(int a) {
        a = find(a);
        p[a] = (a + 1) % sz(p);
        return a;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    DSU dsu(n);

    int _n = n, p;
    while (_n--) {
        cin >> p; p--;
        cout << dsu.unite(p) + 1 << " ";
    }
    return 0;
}
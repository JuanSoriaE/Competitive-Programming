#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

struct DSU {
    vector<int> p, len;
    DSU(int n) : p(n), len(n, 0) { iota(all(p), 0); }

    pair<int, int> find(int a) {
        if (a == p[a]) return {a, 0};
        const auto [pa, la] = find(p[a]);
        p[a] = pa;
        len[a] = len[a] + la;
        return {p[a], len[a]};
    }
    bool unite(int a, int b) {
        p[a] = b;
        len[a]++;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;

    DSU dsu(n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            dsu.unite(a - 1, b - 1);
        } else {
            int c; cin >> c;
            cout << dsu.find(c - 1).second << '\n';
        }
    }

    return 0;
}
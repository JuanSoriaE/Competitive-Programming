#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

struct DSU {
    vector<int> p, size;
    int sets;
    DSU(int n) : p(n), size(n, 1), sets(n) { iota(all(p), 0); }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        sets--;
        return 1;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    DSU AR(n), A(n), R(n);

    int total_A = 0, total_R = 0, m = 0;
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        u--, v--, m++;
        AR.unite(u, v);

        if (t == 1) A.unite(u, v), total_A++;
        else R.unite(u, v), total_R++;

        int R_max = total_R - (A.sets - AR.sets),
            A_max = total_A - (R.sets - AR.sets),
            maxi = (m - (n - AR.sets)) / 2;

        cout << 2 * min({R_max, A_max, maxi}) << '\n';
    }

    return 0;
}
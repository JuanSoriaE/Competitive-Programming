// https://judge.yosupo.jp/problem/lca
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 500000;
constexpr int LOG = 19;

int n;
int p[MAX_N], up[MAX_N][LOG + 1], depth[MAX_N];

void preprocess() {
    depth[0] = -1;
    for (int u = 0; u < n; u++) {
        depth[u] = depth[p[u]] + 1;
        up[u][0] = p[u];
        for (int i = 1; i <= LOG; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int k = depth[u] - depth[v];
    for (int i = 0; i <= LOG; i++)
    if (k & (1 << i)) u = up[u][i];
    if (u == v) return u;

    for (int i = LOG; i >= 0; i--)
    if (up[u][i] != up[v][i])
        u = up[u][i], v = up[v][i];

    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> n >> q;
    for (int i = 1; i < n; i++)
        cin >> p[i];

    preprocess();

    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}
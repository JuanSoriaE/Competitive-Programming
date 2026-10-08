// https://toph.co/p/city-of-atlantis
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;
constexpr int LOG = 17;

vector<pair<int, int>> adj[MAX_N + 1];
int up[MAX_N + 1][LOG + 1], g[MAX_N + 1][LOG + 1];

void dfs(int u = 1, int p = 0, int w = 1) {
    up[u][0] = p;
    g[u][0] = w;
    for (int i = 1; i <= LOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        g[u][i] = __gcd(g[u][i - 1], g[up[u][i - 1]][i - 1]);
    }
    for (auto &[v, w] : adj[u])
    if (v != p) dfs(v, u, w);
}

void reset(const int &n) {
    for (int i = 0; i <= LOG; i++)
        g[0][i] = 1;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

int ans(int u, int p) {
    if (p == 1) return 1;
    int i = LOG;
    while (i >= 0) {
        if (g[u][i] % p == 0)
            u = up[u][i];
        else
            i--;
    }
    return u;
}

void solve(int case_i) {
    int n; cin >> n;
    reset(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs();

    int q; cin >> q;
    cout << "Case " << case_i << ":\n";
    while (q--) {
        int f, p; cin >> f >> p;
        cout << ans(f, p) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}
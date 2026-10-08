#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;

int n;
vector<pair<int, ll>> adj[MAX_N];
int _sz[MAX_N];
ll ans[MAX_N], rev[MAX_N];

ll dfs1(int u, int p = -1) {
    _sz[u] = 1;
    ll ret = 0;
    for (auto &[v, w] : adj[u]) {
        if (v == p) {
            rev[u] = w;
            continue;
        }

        ret += dfs1(v, u) + _sz[v] * w;
        _sz[u] += _sz[v];
    }
    return ret;
}

void dfs2(int u, int p = -1) {
    for (auto &[v, w] : adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] - _sz[v] * w + (n - _sz[v]) * rev[v];
        dfs2(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, a, b; cin >> u >> v >> a >> b;
        u--, v--;

        adj[u].push_back({v, a});
        adj[v].push_back({u, b});
    }

    ans[0] = dfs1(0);
    dfs2(0);

    for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
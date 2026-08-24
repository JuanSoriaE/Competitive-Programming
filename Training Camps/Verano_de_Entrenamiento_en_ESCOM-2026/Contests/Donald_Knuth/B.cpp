#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// cost, sum
pair<ll, ll> dfs(int u, int prev, vector<pair<ll, ll>> &aux, vector<ll> &w, vector<vector<int>> &adj) {
    pair<ll, ll> ret = {0, w[u]};

    for (int &v : adj[u]) {
        if (v == prev) continue;

        auto [a, b] = dfs(v, u, aux, w, adj);
        ret.first += a + b;
        ret.second += b;
    }

    return aux[u] = ret;
}

void compute_ans(int u, int prev, pair<ll, ll> parent, vector<pair<ll, ll>> &aux, vector<vector<int>> &adj, ll &ans) {
    for (int &v : adj[u]) {
        if (v == prev) continue;

        ll child_cost = parent.first - 2LL * aux[v].second + parent.second;
        ans = min(ans, child_cost);
        compute_ans(v, u, {child_cost, parent.second}, aux, adj, ans);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<ll, ll>> aux(n + 1);
    dfs(1, -1, aux, w, adj);
    ll ans = aux[1].first;
    compute_ans(1, -1, aux[1], aux, adj, ans);

    cout << ans << '\n';

    return 0;
}
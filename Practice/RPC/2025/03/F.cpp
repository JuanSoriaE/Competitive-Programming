#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define SZ(x) (ll)(x.size())

void dfs(int node, vector<set<int>> &adj_l, vector<bool> &vst, ll &edges, ll &nodes) {
    if (vst[node]) return;

    vst[node] = true;
    edges += SZ(adj_l[node]);
    nodes++;
    for (int nei : adj_l[node])
        dfs(nei, adj_l, vst, edges, nodes);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<set<int>> adj_l(n + 1);
    int a, b;
    while (m--) {
        cin >> a >> b;
        adj_l[a].insert(b);
        adj_l[b].insert(a);
    }

    vector<bool> vst(n + 1);
    ll edges, nodes, ans = 0;
    for (int i = 1; i <= n; i++) {
        edges = 0; nodes = 0;
        dfs(i, adj_l, vst, edges, nodes);

        ans += (nodes * (nodes - 1) - edges) / 2;
    }

    cout << ans << "\n";
    return 0;
}
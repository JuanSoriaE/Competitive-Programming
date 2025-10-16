// https://cses.fi/problemset/task/1679
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

int n;
vector<vector<int>> adj;

pair<bool, vector<int>> topo_sort() {
    vector<int> order;
    vector<int> in_degree(n + 1, 0);
    for (int u = 0; u <= n; u++)
    for (int v : adj[u]) in_degree[v]++;

    queue<int> q;
    for (int u = 1; u <= n; u++)
    if (in_degree[u] == 0) q.push(u);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        for (int v : adj[u])
        if (--in_degree[v] == 0) q.push(v);
    }

    return {sz(order) == n, order};
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int m; cin >> n >> m;

    adj.resize(n + 1);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    auto [valid, ans] = topo_sort();
    if (!valid) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i : ans)
    cout << i << " ";
    cout << "\n";

    return 0;
}
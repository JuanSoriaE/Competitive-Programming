// https://www.spoj.com/problems/RPLA/
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

vector<vector<int>> topo_sort(int n, vector<vector<int>> &adj) {
    vector<int> in_degree(n, 0);
    for (int u = 0; u < n; u++)
    for (int v : adj[u]) in_degree[v]++;

    queue<pair<int, int>> q;
    for (int u = 0; u < n; u++)
    if (in_degree[u] == 0) {
        q.push({u, 0});
    }

    
    vector<vector<int>> ans(n);
    while (!q.empty()){
        auto [u, r] = q.front(); q.pop();
        ans[r].push_back(u);

        for (int v : adj[u])
        if (--in_degree[v] == 0)
            q.push({v, r + 1});
    }

    return ans;
}

void solve(int t) {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[v].push_back(u);
    }

    vector<vector<int>> ans = topo_sort(n, adj);

    cout << "Scenario #" << (t + 1) << ":\n";
    for (int r = 0; r < n; r++) {
        sort(all(ans[r]));
        for (int u : ans[r])
            cout << (r + 1) << " " << u << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve(i);
    return 0;
}
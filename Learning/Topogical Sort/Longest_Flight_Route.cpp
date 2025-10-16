// https://cses.fi/problemset/task/1680
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
vector<int> _prev;

void topo_sort() {
    vector<int> in_degree(n + 1, 0);
    for (int u = 1; u <= n; u++)
    for (int v : adj[u]) in_degree[v]++;

    vector<int> longest(n + 1, 0);
    longest[1] = 1;

    queue<int> q;
    for (int u = 1; u <= n; u++)
    if (in_degree[u] == 0) q.push(u);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int v : adj[u]) {
            if (--in_degree[v] == 0)
                q.push(v);
            if (longest[u] == 0 || longest[u] + 1 < longest[v])
                continue;

            longest[v] = longest[u] + 1;
            _prev[v] = u;
        }
    }
}

vector<int> longest_path() {
    _prev.resize(n + 1, -1);
    topo_sort();

    vector<int> path;
    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = _prev[cur];
    }

    reverse(all(path));
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int m; cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> path = longest_path();
    if (sz(path) < 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << sz(path) << "\n";
    for (int i : path)
        cout << i << " ";
    cout << "\n";
    return 0;
}
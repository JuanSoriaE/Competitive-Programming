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

#define MAX_N 200000

int in_degree[MAX_N + 1];
int p[MAX_N + 1];

void solve() {
    int n; cin >> n;
    for (int u = 1; u <= n; u++) in_degree[u] = 0;

    vector<vector<int>> adj(n + 1);


    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        if (x > y) {
            adj[u].push_back(v);
            in_degree[v]++;
        } else {
            adj[v].push_back(u);
            in_degree[u]++;
        }
    }

    queue<int> q;

    for (int u = 1; u <= n; u++)
    if (!in_degree[u]) q.push(u);

    int p_i = n;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        p[u] = p_i--;

        for (int &v : adj[u])
        if (--in_degree[v] == 0) q.push(v);
    }

    for (int u = 1; u <= n; u++)
    cout << p[u] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
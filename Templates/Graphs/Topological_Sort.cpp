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

// Recursive Implementation | O(n + m)
int n;
vector<vector<int>> adj;
vector<bool> vst;
vector<int> order;

void dfs(int u) {
    if (vst[u]) return;

    vst[u] = 1;
    for (int v : adj[u]) dfs(v);

    order.push_back(u);
}

void topological_sort() {
    vst.resize(n, false);
    for (int u = 0; u < n; u++)
        dfs(u);

    reverse(all(order));
}

// Kahn's algorithm | O(n + m)
int n;
vector<vector<int>> adj;

pair<bool, vector<int>> topological_sort() {
    vector<int> in_degree(n, 0);
    for (int u = 0; u < n; u++)
    for (int v : adj[u]) in_degree[v]++;

    queue<int> q;
    for (int u = 0; u < n; u++)
    if (in_degree[u] == 0) q.push(u);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        for (int v : adj[u])
        if (--in_degree[v] == 0)
            q.push(v);
    }

    return {sz(order) == n, order};
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
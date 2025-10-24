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

#define MAX_N 500000
int depth_count[MAX_N], max_depth_count[MAX_N];
int prefix[MAX_N + 1], // Cut shallower or equal
    suffix[MAX_N + 1]; // Cut deeper or equal

int dfs(int u, int prev, int d, vector<vector<int>> &adj) {
    int max_depth = d;
    for (int &v : adj[u])
    if (v != prev)
        max_depth = max(max_depth, dfs(v, u, d + 1, adj));

    depth_count[d]++;
    max_depth_count[max_depth]++;

    return max_depth;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) depth_count[i] = 0, max_depth_count[i] = 0;
    prefix[0] = suffix[n] = 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int &v : adj[1])
    dfs(v, 1, 1, adj);

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + max_depth_count[i];
    for (int i = n - 1; i >= 1; i--)
        suffix[i] = suffix[i + 1] + depth_count[i];

    int ans = INT_MAX;
    for (int d = 1; d <= n - 1; d++)
        ans = min(ans, prefix[d - 1] + suffix[d + 1]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
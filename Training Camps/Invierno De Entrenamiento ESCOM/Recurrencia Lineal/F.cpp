#include <bits/stdc++.h>
using namespace std;

#define for0(i, n) for (int i = 0; i < n; i++)
#define pb push_back

void dfs(int root, int p, vector<vector<int>> &g, int prev_color, int &mx, map<pair<int, int>, int> &ans) {
    int color = 1;
    for (int c : g[root]) {
        if (c == p) continue;

        if (color == prev_color) color++;

        ans[{min(root, c), max(root, c)}] = color;
        mx = max(mx, color);

        dfs(c, root, g, color, mx, ans);

        color++;
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    int u, v;
    vector<pair<int, int>> edges(n - 1);

    for0(i, n - 1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);

        edges[i] = {min(u, v), max(u, v)};
    }

    map<pair<int, int>, int> ans;
    int mx = 0;

    dfs(1, 0, g, 0, mx, ans);

    cout << mx << "\n";
    for (pair<int, int> &edge : edges)
        cout << ans[{edge.first, edge.second}] << "\n";

    return 0;
}
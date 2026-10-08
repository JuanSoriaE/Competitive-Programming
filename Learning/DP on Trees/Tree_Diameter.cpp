// https://cses.fi/problemset/task/1131
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

int ans = 0;
vector<int> adj[MAX_N + 1];

int dfs(int u = 1, int prev = -1) {
    int a = 0, b = 0;
    for (int &v : adj[u]) {
        if (v == prev) continue;

        int c = dfs(v, u);
        if (c > a) b = a, a = c;
        else if (c > b) b = c;
    }
    ans = max(ans, a + b);

    return a + 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    cout << ans << '\n';

    return 0;
}
// https://cses.fi/problemset/task/1130
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

vector<int> adj[MAX_N + 1];

int dp[MAX_N + 1][2];

void dfs(int u = 1, int prev = -1) {
    int sum = 0;
    for (int &v : adj[u]) {
        if (v == prev) continue;
        dfs(v, u);
        sum += max(dp[v][0], dp[v][1]);
    }

    dp[u][0] = sum;
    for (int &v : adj[u]) {
        if (v == prev) continue;
        dp[u][1] = max(
            dp[u][1],
            dp[v][0] + sum - max(dp[v][0], dp[v][1]) + 1
        );
    }
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
    cout << max(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
// https://atcoder.jp/contests/dp/tasks/dp_p
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;
constexpr int MOD = 1000000007;

vector<int> adj[MAX_N + 1];

ll dp[MAX_N + 1][2];

void dfs(int u = 1, int prev = -1) {
    dp[u][0] = dp[u][1] = 1;
    for (int &v : adj[u]) {
        if (v == prev) continue;
        dfs(v, u);

        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1]) % MOD) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
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
    cout << (dp[1][0] + dp[1][1]) % MOD << '\n';

    return 0;
}
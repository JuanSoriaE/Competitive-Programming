// https://codeforces.com/contest/161/problem/D
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 50000;
constexpr int MAX_K = 500;

int k;
ll ans = 0;
int dp[MAX_N + 1][MAX_K + 1];

vector<int> adj[MAX_N + 1];

void dfs(int u = 1, int prev = -1) {
    for (int &v : adj[u]) {
        if (v == prev) continue;
        dfs(v, u);

        for (int i = 0; i < k; i++)
            dp[u][i + 1] += dp[v][i];
    }
    dp[u][0] = 1;

    ans += dp[u][k];

    ll sum = 0;
    for (int &v : adj[u]) {
        if (v == prev) continue;

        for (int i = 1; i < k; i++)
            sum += dp[v][i - 1] * (dp[u][k - i] - dp[v][k - i - 1]);
    }

    ans += sum / 2;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    cout << ans << '\n';

    return 0;
}
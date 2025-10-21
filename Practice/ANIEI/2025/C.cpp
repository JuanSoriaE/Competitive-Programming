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

#define MAX_N 1000
#define MAX_O 1000

int n, m, k;
vector<vector<int>> adj;
bool vst[MAX_N + 1] = {false};

int o, T;
int order[MAX_O + 1];

int weights[MAX_O];
int profit[MAX_O];


int dist(int start, int end) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    fill(vst, vst + n + 1, false);

    while (!q.empty()) {
        auto &[cur, d] = q.front(); q.pop();
        vst[cur] = true;
        if (cur == end) return d;

        for (int &v : adj[cur])
        if (!vst[v]) vst[v] = true, q.push({v, d + 1});
    }

    return -1;
}

int knapsack(int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    for (int w = 0; w <= W; w++) {
        dp[i][w] = dp[i - 1][w];
        if (w >= weights[i - 1])
            dp[i][w] = max(dp[i][w], dp[i - 1][w - weights[i - 1]] + profit[i - 1]);
    }

    return dp[n][W];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> o >> T;
    for (int i = 0; i < o; i++) cin >> order[i];
    order[o] = 1;

    bool possible = true;
    int total_req = dist(1, order[0]);
    if (total_req == -1) possible = false;

    int extra_n = 0;
    for (int i = 0; i < o; i++) {
        int d = dist(order[i], order[i + 1]);
        if (d == -1) possible = false;
        
        total_req += d * k;

        int special, prof; cin >> special >> prof;
        int d1 = dist(order[i], special),
            d2 = dist(special, order[i + 1]);
        if (d1 == -1) continue;

        weights[extra_n] = (d1 + d2 - d) * k;
        profit[extra_n++] = prof;
    }


    if (possible) cout << knapsack(extra_n, T - total_req) << '\n';
    else cout << "impossible\n";

    return 0;
}
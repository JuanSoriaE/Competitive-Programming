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

pair<ll, int> dfs(int cur, vector<vector<int>> &adj) {
    int a = 0, b = 0;
    ll res = 0;

    for (int &v : adj[cur]) {
        auto [v_res, v_max_depth] = dfs(v, adj);

        if (v_max_depth > a) b = a, a = v_max_depth;
        else if (v_max_depth > b) b = v_max_depth;

        res += v_res;
    }

    return {res + b + 1, a + 1};
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int u = 2; u <= n; u++) {
        int p; cin >> p;
        adj[p].push_back(u);
    }

    cout << dfs(1, adj).first << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
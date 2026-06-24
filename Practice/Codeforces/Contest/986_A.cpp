#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100000
#define MAX_K 100

vector<int> adj[MAX_N + 1];
vector<int> nodes_per_good[MAX_K + 1];
int dist[MAX_N + 1][MAX_K + 1];

void compute_good_dist(int g) {
    queue<pair<int, int>> q;
    for (int &u : nodes_per_good[g]) {
        dist[u][g] = 0;
        q.push({u, 0});
    }

    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();

        for (int &v : adj[u])
        if (dist[v][g] == INT_MAX) {
            dist[v][g] = d + 1;
            q.push({v, d + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, k, s; cin >> n >> m >> k >> s;
    for (int u = 1; u <= n; u++) {
        int a; cin >> a;
        nodes_per_good[a].push_back(u);
        fill(dist[u] + 1, dist[u] + k + 1, INT_MAX);
    }

    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int g = 1; g <= k; g++)
        compute_good_dist(g);

    for (int u = 1; u <= n; u++) {
        sort(dist[u] + 1, dist[u] + k + 1);
        cout << accumulate(dist[u] + 1, dist[u] + s + 1, 0) << ' ';
    }
    cout << '\n';

    return 0;
}
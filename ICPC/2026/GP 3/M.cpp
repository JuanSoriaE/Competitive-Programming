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
constexpr int MAX_K = 10;

vector<pair<int, int>> adj[MAX_N + 1];
ll dist[MAX_N + 1][MAX_K + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, f, w; cin >> u >> v >> f >> w;
        adj[u].push_back({v, f});
        adj[v].push_back({u, f});

        if (w != -1) {
            adj[u].push_back({v, -w});
            adj[v].push_back({u, -w});
        }
    }

    for (int i = 1; i <= n; i++)
        fill(dist[i], dist[i] + k + 1, LLONG_MAX);

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>,
        greater<pair<ll, pair<int, int>>>> pq;
    pq.push({0, {1, 0}});
    for (int i = 0; i <= k; i++)
        dist[1][i] = 0;

    ll ans = LLONG_MAX;
    while (!pq.empty()) {
        auto [d, p] = pq.top(); pq.pop();
        auto [u, cur_k] = p;

        if (u == n) {
            ans = min(ans, d);
            continue;
        }

        for (auto &[v, w] : adj[u]) {
            if (w > 0) {
                if (d + w < dist[v][cur_k]) {
                    dist[v][cur_k] = d + w;
                    pq.push({d + w, {v, cur_k}});
                }
            } else if (cur_k < k) {
                if (d - w < dist[v][cur_k + 1]) {
                    dist[v][cur_k + 1] = d - w;
                    pq.push({d - w, {v, cur_k + 1}});
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
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

short n;
ll h, k, h2, k2;
vector<vector<short>> adj;
vector<bool> end_points;

short BFS(short start) {
    vector<bool> vst(n + 1, false);
    queue<pair<short, short>> q; q.push({start, 0});

    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        if (vst[u]) continue;
        if (end_points[u]) return d + 1;

        vst[u] = 1;
        for (short v : adj[u])
        if (!vst[v]) q.push({v, d + 1});
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> h >> k;
    h2 = h * h; k2 = k * k;
    vector<vector<int>> points(n + 1, vector<int>(3));
    adj.resize(n + 1);
    end_points.resize(n + 1, false);
    
    bool finished = 0, possible = 0;
    for (short u = 1; u <= n; u++) {
        cin >> points[u][0] >> points[u][1] >> points[u][2];

        if (points[u][1] == 0)
            finished = 1;
        if (points[u][2] && -points[u][1] <= h) {
            end_points[u] = 1;
            possible = 1;
        }
    }
    int a, b; cin >> a >> b;
    if (finished) {
        cout << 0 << "\n";
        return 0;
    }
    if (!possible) {
        cout << -1 << "\n";
        return 0;
    }

    // Adjacency list
    for (short u = 1; u <= n; u++)
    for (short v = u + 1; v <= n; v++) {
        ll dist = ((ll)(points[u][0] - points[v][0]) * (points[u][0] - points[v][0]) + (ll)(points[u][1] - points[v][1]) * (points[u][1] - points[v][1]));
        bool reachable_h = h2 >= dist, reachable_k = k2 >= dist;
        if (points[u][2]) {
            if (reachable_h)
                adj[u].push_back(v);
            if (reachable_k)
                adj[v].push_back(u);
        }

        if (points[v][2]) {
            if (reachable_h)
                adj[v].push_back(u);
            if (reachable_k)
                adj[u].push_back(v);
        }
    }

    short start = 0;
    for (short u = 1; u <= n && start == 0; u++)
        if (points[u][0] == a && points[u][1] == b)
            start = u;

    cout << BFS(start) << "\n";

    return 0;
}
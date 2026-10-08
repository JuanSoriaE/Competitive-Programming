#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// Dinic's algorithm | O(V^2E)
struct Dinic {
    const ll INF = 1e18;
    struct Edge {
        int u, v;
        ll c, f;
        Edge(int u, int v, ll c) : u(u), v(v), c(c), f(0) {}
    };

    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    queue<int> q;
    int n, m, s, t;

    Dinic(int n, int s, int t) : n(n), m(0), s(s), t(t), adj(n), level(n), ptr(n) {}
    void add_edge(int u, int v, ll c) {
        edges.push_back({u, v, c});
        edges.push_back({v, u, 0});
        adj[u].push_back(m++);
        adj[v].push_back(m++);
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int &i : adj[u]) {
                if (edges[i].c == edges[i].f ||
                    level[edges[i].v] != -1) continue;
                level[edges[i].v] = level[u] + 1;
                q.push(edges[i].v);
            }
        }
        return level[t] != -1;
    }
    ll dfs(int u, ll pushed) {
        if (pushed == 0 || u == t) return pushed;
        for (int &ci = ptr[u]; ci < sz(adj[u]); ci++) {
            int i = adj[u][ci];
            int v = edges[i].v;
            if (level[u] + 1 != level[v]) continue;
            ll tr = dfs(v, min(pushed, edges[i].c - edges[i].f));
            if (tr == 0) continue;
            edges[i].f += tr;
            edges[i ^ 1].f -= tr;
            return tr;
        }
        return 0;
    }
    ll max_flow() {
        ll f = 0;
        while (true) {
            fill(all(level), -1),
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(all(ptr), 0);
            while (ll pushed = dfs(s, INF))
                f += pushed;
        }
        return f;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
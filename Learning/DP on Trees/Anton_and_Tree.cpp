// https://codeforces.com/contest/734/problem/E
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

int c[MAX_N + 1];
vector<int> adj[MAX_N + 1];

int p[MAX_N + 1], _sz[MAX_N + 1];

int find(int a) { return a == p[a] ? a : p[a] = find(p[p[a]]); }
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;

    if (_sz[a] > _sz[b]) swap(a, b);
    p[a] = b;
    _sz[b] += _sz[a];
}

int dfs(int u, int prev, int &diam) {
    int a = 0, b = 0;
    for (int &v : adj[u]) {
        if (v == prev) continue;
        int c = dfs(v, u, diam);

        if (c > a) b = a, a = c;
        else if (c > b) b = c;
    }

    diam = max(diam, a + b);
    return a + 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];

    vector<pair<int, int>> edges;
    iota(p, p + n + 1, 0); fill(_sz, _sz + n + 1, 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        if (c[u] == c[v]) unite(u, v);
        else edges.push_back({u, v});
    }

    for (auto &[u, v] : edges) {
        u = find(u), v = find(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int diam = 0;
    dfs(find(1), -1, diam);

    cout << ceil(diam, 2) << '\n';

    return 0;
}
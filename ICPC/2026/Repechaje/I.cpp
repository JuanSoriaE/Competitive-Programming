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

ll a[MAX_N];
vector<int> adj[MAX_N];
int in_deg[MAX_N], ans[MAX_N];

int p[MAX_N], _sz[MAX_N];

int find(int a) { return a == p[a] ? a : p[a] = find(p[p[a]]); }
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;

    if (_sz[a] > _sz[b]) swap(a, b);
    p[a] = b;
    _sz[b] += _sz[a];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    iota(p, p + n, 0);
    fill(_sz, _sz + n, 1);

    vector<pair<pair<int, int>, char>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v; char c; cin >> u >> v >> c;
        u--, v--;

        if (c == '=') unite(u, v);
        else edges.push_back({{u, v}, c});
    }

    for (auto &[p, c] : edges) {
        auto &[u, v] = p;
        u = find(u), v = find(v);

        if (c == '<') adj[u].push_back(v);
        else adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    for (int &v : adj[i]) in_deg[v]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
    if (!in_deg[i]) {
        q.push(i);
        ans[i] = 1;
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int &v : adj[u]) {
            ans[v] = max(ans[v], ans[u] + 1);
            if (--in_deg[v] == 0)
                q.push(v);
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += ans[find(i)] * a[i];

    cout << sum << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[find(i)] << ' ';
    cout << '\n';

    return 0;
}
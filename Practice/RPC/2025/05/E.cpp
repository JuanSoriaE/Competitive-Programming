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

string bfs(string u, umap<string, vector<string>> &adj, uset<string> &vst, umap<string, ll> &h) {
    queue<string> q; q.push(u);
    string mx_u = u;

    while (!q.empty()) {
        string cur = q.front(); q.pop();
        if (vst.count(cur)) continue;

        vst.insert(cur);
        if (h[cur] > h[mx_u])
            mx_u = cur;

        if (adj.count(cur))
        for (string &v : adj[cur]) q.push(v);
    }

    return mx_u;
}

void solve(int t) {
    int n, m; cin >> n >> m;
    umap<string, ll> h;
    vector<string> nodes(n);
    ll aux;
    for (int i = 0; i < n; i++) {
        cin >> nodes[i] >> aux;
        h[nodes[i]] = aux;
    }

    umap<string, vector<string>> adj;
    string u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    uset<string> vst;
    vector<string> ans;
    for (string &u : nodes) {
        if (vst.count(u)) continue;

        ans.push_back(bfs(u, adj, vst, h));
    }
    sort(all(ans));
    cout << "Case " << t << ":\n";
    for (string &u : ans)
        cout << u << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}
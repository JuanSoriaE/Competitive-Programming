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

#define MAX_N 100000
int cnt[MAX_N + 1] = {0};

int n, m;
vector<vector<int>> adj;

void bfs(int start) {
    queue<int> q; q.push(start);
    vector<bool> vst(n + 1, false);
    vst[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt[u]++;

        for (int &v : adj[u])
        if (!vst[v]) {
            vst[v] = true;
            q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    int a, b; cin >> a >> b;
    bfs(a); bfs(b);
    for (int u = 1; u <= n; u++)
    if (cnt[u] == 2) {
        cout << "yes\n" << u << '\n';
        return 0;
    }

    cout << "no\n";
    return 0;
}
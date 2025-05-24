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
#define pii pair<int, int>
#define fst first
#define snd second
#define rep(i, s, n) for (int i = s; i < n; i++)

vector<vector<int>> adj;
//           global local
vector<bool> used,  vst;
vector<int> p; // link to parent

pii dfs(int u, int prev) {
    pii ans = {1, u};
    p[u] = prev;
    vst[u] = 1;
    for (int &v : adj[u]) {
        if (used[v] || v == prev) continue;

        pii res = dfs(v, u);
        res.fst++;
        ans = max(ans, res); // handle tie using .second (node)
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, {});
    p.resize(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<array<int, 3>> ans;
    int apples = n;
    used.assign(n + 1, false);
    while (apples) {
        vst.assign(n + 1, false);
        rep(u, 1, n + 1) {
            if (used[u] || vst[u]) continue;

            auto [d1, x] = dfs(u, -1);
            auto [d2, y] = dfs(x, -1);
            ans.push_back({d2, max(x, y), min(x, y)});

            // Delete path
            while (y != -1) {
                used[y] = 1;
                y = p[y];
                apples--;
            }
        }
    }

    sort(all(ans), greater<array<int, 3>>());
    for (const auto &[d, u, v] : ans)
        cout << d << " " << u << " " << v << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
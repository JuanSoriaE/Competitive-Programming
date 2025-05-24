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

vector<vector<int>> adj;
vector<umap<int, int>> mp;
umap<int, vector<int>> querys; // u: k1, k2, ...
vector<umap<int, int>> ans;

void merge(int u, int v) {
    if (sz(mp[u]) < sz(mp[v]))
        swap(mp[u], mp[v]);

    for (auto &[k, val] : mp[v])
        mp[u][k] += val;
}

void dfs(int u) {
    for (int &v : adj[u]) {
        dfs(v);
        merge(u, v);
    }

    for (int &k : querys[u])
        ans[u][k] = mp[u][k];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    mp.resize(n + 1);
    ans.resize(n + 1);
    int k;
    for (int u = 1; u <= n; u++) {
        cin >> k;
        mp[u][k]++;
    }

    adj.resize(n + 1);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    //           u    k
    vector<pair<int, int>> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> u >> k;
        qs[i] = {u, k};
        querys[u].push_back(k);
    }

    dfs(1);
    for (int i = 0; i < q; i++)
        cout << ans[qs[i].first][qs[i].second] << "\n";

    return 0;
}
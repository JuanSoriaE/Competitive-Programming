#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

void merge(int u, int v, vector<map<int, int>> &mp) {
    if (sz(mp[u]) < sz(mp[v]))
        swap(mp[u], mp[v]);
    for (auto &[k, v] : mp[v])
        mp[u][k] += v;
}

ll dfs(int u, vector<vector<int>> &t, vector<map<int, int>> &mp, vector<int> &s) {
    ll ret = 0;
    for (int &v : t[u]) {
        ret += dfs(v, t, mp, s);
        merge(u, v, mp);
    }

    if (s[u] != -1)
        mp[u][s[u]]++;
    else if (!mp[u].empty()) {
        ll maxi = (*mp[u].rbegin()).first;
        ret += maxi;
        if (--mp[u][maxi] == 0)
            mp[u].erase(maxi);
    }

    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];

    vector<vector<int>> t(n + 1);
    vector<bool> root(n + 1, true);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        t[u].push_back(v);
        root[v] = false;
    }

    vector<map<int, int>> mp(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    if (root[i]) ans += dfs(i, t, mp, s);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
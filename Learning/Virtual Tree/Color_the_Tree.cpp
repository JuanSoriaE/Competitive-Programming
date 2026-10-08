// https://codeforces.com/gym/104128/problem/E
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

vector<int> adj[MAX_N + 1];

// LCA
vector<pair<int, int>> euler;
int in[MAX_N + 1], d[MAX_N + 1];

// Virtual Tree
vector<int> X[MAX_N];
vector<int> adj_vt[MAX_N + 1];

template<typename T>
struct SparseTable {
    int n, K;
    vector<vector<T>> st;
    SparseTable(const vector<T> &a) : n(sz(a)), K(log2_floor(n)), st(K + 1, vector<T>(n)) {
        copy(all(a), st[0].begin());
        for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    T query(int l, int r) {
        if (l > r) swap(l, r);
        int i = log2_floor(r - l + 1);
        return f(st[i][l], st[i][r - (1 << i) + 1]);
    }
    T f(T &a, T &b) { return min(a, b); }
    int log2_floor(int x) { return 31 - __builtin_clz(x); }
};

// LCA
void dfs_lca(int u = 1, int prev = 0, int cur_d = 0) {
    d[u] = cur_d;
    in[u] = sz(euler);
    euler.push_back({cur_d, u});
    for (int &v : adj[u]) {
        if (v == prev) continue;
        dfs_lca(v, u, cur_d + 1);
        euler.push_back({cur_d, u});
    }

    X[cur_d].push_back(u); // For VT
}

int lca(int u, int v, SparseTable<pair<int, int>> &st_lca) {
    return st_lca.query(in[u], in[v]).second;
}

// Virtual Tree
bool above(int u, int v, SparseTable<pair<int, int>> &st_lca) {
    return lca(u, v, st_lca) == u;
}

bool comp(const int &u, const int &v) {
    return in[u] < in[v];
}

int virtual_tree(vector<int> &X, SparseTable<pair<int, int>> &st_lca) {
    sort(all(X), comp);

    int n = sz(X);
    for (int i = 0; i < n - 1; i++)
        X.push_back(lca(X[i], X[i + 1], st_lca));

    sort(all(X), comp);
    X.erase(unique(all(X)), X.end());
    for (int &u : X) adj_vt[u].clear();

    n = sz(X);
    vector<int> stk;
    stk.push_back(X[0]);

    for (int i = 1; i < n; i++) {
        int u = X[i];
        while (sz(stk) >= 2 && !above(stk.back(), u, st_lca)) {
            adj_vt[stk[sz(stk) - 2]].push_back(stk.back());
            stk.pop_back();
        }
        stk.push_back(u);
    }

    while (sz(stk) >= 2) {
        adj_vt[stk[sz(stk) - 2]].push_back(stk.back());
        stk.pop_back();
    }

    return stk[0];
}

// Solution
ll dfs(int u, int prev, const int &D, SparseTable<int> &st) {
    ll sum = 0;
    for (int &v : adj_vt[u])
        sum += dfs(v, u, D, st);

    int l = D - d[u], r = D - d[prev] - 1;
    ll query = st.query(l, r);

    return sum == 0 ? query : min(sum ,query);
}

void reset(int n) {
    for (int i = 1; i <= n; i++)
        adj[i].clear(), X[i - 1].clear();
    euler.clear();
}

void solve() {
    d[0] = -1;
    int n; cin >> n;
    reset(n);

    vector<int> a(n);
    for (int &i : a) cin >> i;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_lca();
    SparseTable st_lca(euler);

    SparseTable st(a);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    if (!X[i].empty()) {
        int root = virtual_tree(X[i], st_lca);
        ans += dfs(root, 0, i, st);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
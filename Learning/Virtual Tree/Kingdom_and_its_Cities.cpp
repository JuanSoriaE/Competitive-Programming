// https://codeforces.com/contest/613/problem/D
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define ST SparseTable<pair<int, int>>

constexpr int MAX_N = 100000;

vector<int> adj[MAX_N + 1];
bool important[MAX_N + 1];

// LCA
vector<pair<int, int>> euler;
int in[MAX_N + 1], d[MAX_N + 1];

// Virtual Tree
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
void dfs_lca(int u = 1, int p = 0, int cur_d = 0) {
    d[u] = cur_d;
    in[u] = sz(euler);
    euler.push_back({cur_d, u});
    for (int &v : adj[u]) {
        if (v == p) continue;
        dfs_lca(v, u, cur_d + 1);
        euler.push_back({cur_d, u});
    }
}

int lca(int u, int v, ST &st) {
    return st.query(in[u], in[v]).second;
}

// Virtual Tree
bool above(int u, int v, ST &st) { return lca(u, v, st) == u; }
bool comp(const int &u, const int &v) { return in[u] < in[v]; }

int vt(vector<int> &v, ST &st) {
    sort(all(v), comp);

    int n = sz(v);
    for (int i = 0; i < n - 1; i++)
        v.push_back(lca(v[i], v[i + 1], st));


    sort(all(v), comp);
    v.erase(unique(all(v)), v.end());
    for (int &u : v) adj_vt[u].clear();


    vector<int> stk;
    stk.push_back(v[0]);

    for (int i = 1; i < sz(v); i++) {
        int u = v[i];
        while (sz(stk) > 1 && !above(stk.back(), u, st)) {
            adj_vt[stk[sz(stk) - 2]].push_back(stk.back());
            stk.pop_back();
        }
        stk.push_back(u);
    }
    while (sz(stk) > 1) {
        adj_vt[stk[sz(stk) - 2]].push_back(stk.back());
        stk.pop_back();
    }

    return stk[0];
}

pair<int, bool> dfs(int u, int p = 0) {
    int connected = 0, res = 0;
    for (int &v : adj_vt[u]) {
        if (v == p) continue;

        auto [a, b] = dfs(v, u);
        if ((important[u] && important[v] && (d[v] - d[u] == 1)) || a == -1)
            return {-1, false};

        res += a;
        connected += b;
    }

    if (important[u]) return {res + connected, 1};
    return {res + (connected > 1 ? 1 : 0), (connected > 1 ? 0 : connected)};
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_lca();
    ST st(euler);

    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> X(k);
        for (int &i : X) { cin >> i; important[i] = true; }

        cout << dfs(vt(X, st)).first << '\n';

        for (int &i : X) important[i] = false;
    }

    return 0;
}
// https://codeforces.com/contest/1142/problem/B
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
constexpr int MAX_M = 200000;
constexpr int LOG = 18;

int p[MAX_N + 1], a[MAX_M + 1], nxt[MAX_N + 1], closest[MAX_N + 1];

vector<int> adj[MAX_M + 1];
bool vst[MAX_M + 1];
int up[MAX_M + 1][LOG + 1], depth[MAX_M + 1];

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
        int i = log2_floor(r - l + 1);
        return f(st[i][l], st[i][r - (1 << i) + 1]);
    }
    T f(T &a, T &b) { return min(a, b); }
    int log2_floor(int n) { return 31 - __builtin_clz(n); }
};

void dfs(int u, int p = 0) {
    vst[u] = true;
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for (int i = 1; i <= LOG; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int &v : adj[u]) dfs(v, u);
}

int kth_ancestor(int u, int k) {
    for (int i = 0; i <= LOG; i++)
    if (k & (1 << i)) u = up[u][i];
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        nxt[p[i - 1]] = p[i];
    }
    nxt[p[n]] = p[1];

    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = m; i > 0; i--) {
        int nxt_i = closest[nxt[a[i]]];
        if (nxt_i) adj[nxt_i].push_back(i);
        closest[a[i]] = i;
    }

    for (int i = m; i > 0; i--)
    if (!vst[i]) dfs(i);

    vector<int> ans(m + 1);
    for (int i = 1; i <= m; i++) {
        int x = kth_ancestor(i, n - 1);
        ans[i] = x ? x : INT_MAX;
    }

    SparseTable st(ans);
    while (q--) {
        int l, r; cin >> l >> r;
        int e = st.query(l, r);
        cout << (e <= r ? '1' : '0');
    }
    cout << '\n';

    return 0;
}
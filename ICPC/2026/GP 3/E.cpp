#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define vi vector<int>

bool dfs(int a, int L, vector<vi> &g, vi &btoa, vi &A, vi&B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}

int hopcroftKrap(vector<vi> &g, vi &btoa) {
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        cur.clear();
        for (int a : btoa) if (a != -1) A[a] = -1;
        for (int a = 0; a < sz(g); a++) if (A[a] == 0) cur.push_back(a);
        for (int lay = 1;; lay++) {
            bool is_last = 0;
            next.clear();
            for (int a : cur) for (int b : g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay;
                    is_last = 1;
                } else if (btoa[b] != a && !B[b]) {
                    B[b] = lay;
                    next.push_back(btoa[b]);
                }
            }
            if (is_last) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
        }
        for (int a = 0; a < sz(g); a++)
            res += dfs(a, 0, g, btoa, A, B);
    }
    return 0;
}

bool share_vertex(const pair<int, int> &e1, const pair<int, int> &e2) {
    auto &[a, b] = e1;
    auto &[c, d] = e2;
    return a == c || a == d || b == c || b == d;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m1, m2; cin >> n >> m1 >> m2;
    if (m1 != m2) {
        cout << "-1\n";
        return 0;
    }

    int m = m1;
    vector<pair<int, int>> E1(m), E2(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        E1[i] = {min(u, v), max(u, v)};
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        E2[i] = {min(u, v), max(u, v)};
    }

    set<pair<int, int>> common;
    for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
    if (E1[i] == E2[j])
        common.insert(E1[i]);

    vector<vi> g(m);
    for (int i = 0; i < m; i++) {
        if (common.count(E1[i])) continue;
        for (int j = 0; j < m; j++) {
            if (!common.count(E2[j]) &&
                share_vertex(E1[i], E2[j]))
                g[i].push_back(j);
        }
    }

    vector<int> btoa(m, -1);
    int cost_1 = hopcroftKrap(g, btoa);
    int ans = cost_1 + (m - sz(common) - cost_1) * 2;
    cout << ans << '\n';

    return 0;
}
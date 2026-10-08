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

int in[MAX_N];
vector<int> adj_vt[MAX_N];

bool above(int &u, int &v) { return lca(u, v) == u; }
bool comp(int &u, int &v) { return in[u] < in[v]; }

int virtual_tree(vector<int> &v) {
    sort(all(v), comp);

    int n = sz(v);
    for (int i = 0; i < n - 1; i++)
        v.push_back(lca(v[i], v[i + 1]));

    sort(all(v), comp);
    v.erase(unique(all(v)), v.end());
    for (int &u : v) adj_vt[u].clear();

    vector<int> stk;
    for (int i = 0; i < sz(v); i++) {
        int u = v[i];
        while (sz(stk) > 1 && !above(stk.back(), u)) {
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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
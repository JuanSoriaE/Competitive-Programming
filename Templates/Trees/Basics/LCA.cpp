#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 500000;

vector<int> adj[MAX_N];
int in[MAX_N];

vector<pair<int, int>> euler;
void dfs(int u = 0, int prev = -1, int d = 0) {
    in[u] = sz(euler);
    euler.push_back({d, u});
    for (int &v : adj[u]) {
        if (v == prev) continue;
        dfs(v, u, d + 1);
        euler.push_back({d, u});
    }
}

int lca(int &u, int &v, SparseTable<pair<int, int>> &st) {
    return st.query(in[u], in[v]).second;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
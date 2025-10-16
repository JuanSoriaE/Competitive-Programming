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

#define MAX_N 10000
#define MAX_M 10000

int n, m; // Number of nodes at left (1...n) and right (1...m) respectively
vector<vector<int>> adj; // From left to right nodes

bool vst[MAX_N + 1] = {false}, vst_aux[MAX_N + 1] = {false};
int match[MAX_M + 1] = {0};

bool try_kuhn(int u) {
    if (vst[u]) return false;
    vst[u] = true;

    for (int &v : adj[u])
    if (!match[v] || try_kuhn(match[v])) {
        match[v] = u;
        return true;
    }

    return false;
}

// Kuhn's algorithm | O(n*m)
int maximum_bipartite_matching() {
    // Heurstic Speedup
    for (int u = 1; u <= n; u++)
    for (int v : adj[u])
    if (!match[v]) {
        match[v] = u;
        vst_aux[u] = true;
        break;
    }

    for (int u = 1; u <= n; u++) {
        if (vst_aux[u]) continue;

        fill(vst, vst + n + 1, false);
        try_kuhn(u);
    }

    int res = 0;
    for (int v = 1; v <= m; v++)
    if (match[v]) res++;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
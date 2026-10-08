#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// Articulation Points
constexpr int MAX_N = 100000;

vector<int> adj[MAX_N];
int low[MAX_N], discovered[MAX_N];

int timer = 1;
void dfs(int u, int p = -1) {
    int children = 0;
    low[u] = discovered[u] = timer++;

    for (int &v : adj[u]) {
        if (v == p) continue;
        if (!discovered[v]) {
            children++;
            dfs(v, u);
            if (p != -1 && discovered[u] <= low[v]) {
                /*u is an Articulation Point*/
            }
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], discovered[v]);
        }
    }

    if (p == -1 && children > 1) { /*u is an Articulation Point*/ }
}

int timer = 1;
void dfs(int u, int p = -1) {
    discovered[u] = low[u] = timer++;

    for (int &v : adj[u]) {
        if (v == p) continue;
        if (!discovered[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (discovered[u] < low[v]) { /*(u, v) is a Bridge*/ }
        } else {
            low[u] = min(low[u], discovered[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
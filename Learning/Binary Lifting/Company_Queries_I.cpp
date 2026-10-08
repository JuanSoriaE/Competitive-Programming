// https://cses.fi/problemset/task/1687
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
constexpr int LOG = 18;

int n;
vector<int> adj[MAX_N + 1];
int p[MAX_N + 1], up[MAX_N + 1][LOG + 1];

void preprocess() {
    for (int u = 1; u <= n; u++)
        up[u][0] = p[u];

    for (int i = 1; i <= LOG; i++)
    for (int u = 2; u <= n; u++)
        up[u][i] = up[up[u][i - 1]][i - 1];
}

int kth_ancestor(int u, int k) {
    for (int i = 0; i <= LOG; i++)
    if (k & (1 << i)) u = up[u][i];
    return u == 0 ? -1 : u;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> n >> q;
    for (int u = 2; u <= n; u++) cin >> p[u];

    preprocess();

    while (q--) {
        int x, k; cin >> x >> k;
        cout << kth_ancestor(x, k) << '\n';
    }

    return 0;
}
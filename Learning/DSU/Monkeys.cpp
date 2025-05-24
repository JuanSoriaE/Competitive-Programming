// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/E
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

struct DSU {
    vector<int> p, size;
    vector<vector<int>> children;
    DSU(int n) : p(n), size(n, 1), children(n) { iota(all(p), 0); for (int i = 0; i < n; i++) children[i].push_back(i); }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    vector<int> unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return {};

        if (a < b) swap(a, b);
        p[a] = b;
        size[b] += size[a];

        vector<int> new_falling;
        if (b == 1) new_falling.insert(new_falling.end(), all(children[a]));
        else children[b].insert(children[b].end(), all(children[a]));

        return new_falling;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> edges[i].first >> edges[i].second;

    vector<pair<int, int>> releases(m);
    for (int i = 0; i < m; i++)
        cin >> releases[i].first >> releases[i].second;

    vector<pair<int, int>> final_edges = edges;
    for (auto &[u, h] : releases)
        if (h == 1) final_edges[u].first = -1;
        else final_edges[u].second = -1;

    // Create final graph
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) {
        if (final_edges[i].first != -1) dsu.unite(i, final_edges[i].first);
        if (final_edges[i].second != -1) dsu.unite(i, final_edges[i].second);
    }

    vector<int> ans(n + 1); ans[1] = -1;
    for (int i = m - 1; i >= 0; i--) {
        int u = releases[i].first, h = releases[i].second;
        int v = h == 1 ? edges[u].first : edges[u].second;
        if (v == -1) continue;

        for (int &m : dsu.unite(u, v))
            ans[m] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";

    return 0;
}
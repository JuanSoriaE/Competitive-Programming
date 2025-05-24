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

struct TreeNode {
    int v;
    TreeNode *l;
    TreeNode *r;
    TreeNode() : v(0), l(nullptr), r(nullptr) {}
    TreeNode(int _v) : v(_v), l(nullptr), r(nullptr) {}
    TreeNode(int _v, TreeNode *_l, TreeNode *_r) : v(_v), l(_l), r(_r) {}
};

vector<vector<int>> adj_list;
vector<int> down1, down2, up;
// First DFS: Compute down1 and down2 (longest paths in subtrees)
void dfs1(int u, int prev) {
    down1[u] = down2[u] = 0;
    for (int v : adj_list[u]) {
        if (v == prev) continue;

        dfs1(v, u);
        int path_length = down1[v] + 1;
        if (path_length > down1[u]) {
            down2[u] = down1[u];
            down1[u] = path_length;
        } else if (path_length > down2[u]) {
            down2[u] = path_length;
        }
    }
}

// Second DFS: Compute up (longest path through parent)
void dfs2(int u, int prev) {
    for (int v : adj_list[u]) {
        if (v == prev) continue;

        if (down1[u] == down1[v] + 1) {
            up[v] = max(up[u], down2[u]) + 1;
        } else {
            up[v] = max(up[u], down1[u]) + 1;
        }
        dfs2(v, u);
    }
}

vector<int> compute_longest_paths(int n, vector<int> &longest_path_of_island) {
    down1.assign(n + 1, 0);
    down2.assign(n + 1, 0);
    up.assign(n + 1, 0);

    dfs1(1, 0);
    dfs2(1, 0);

    vector<int> longest_paths(n + 1);
    for (int u = 1; u <= n; u++)
        longest_paths[u] = max(down1[u], up[u]) + 1;
    return longest_paths;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
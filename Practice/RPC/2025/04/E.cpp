#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int(x.size()))

void print_v(vector<int> &v) { for (int &x : v) cout << x << " "; cout << "\n"; }

vector<vector<int>> adj_list;
vector<int> island_of;

void visit(int u, int prev, vector<bool> &vst, int island) {
    if (vst[u]) return;

    vst[u] = true;
    island_of[u] = island;
    for (int &v : adj_list[u])
    if (v != prev) visit(v, u, vst, island);
}

vector<int> down1, down2, up;  // DP arrays
// First DFS: Compute down1 and down2 (longest paths in subtrees)
void dfs1(int u, int parent, vector<bool> &vst) {
    if (vst[u]) return;

    vst[u] = true;
    down1[u] = down2[u] = 0;
    for (int v : adj_list[u]) {
        if (v == parent) continue;
        dfs1(v, u, vst);
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
void dfs2(int u, int parent, vector<bool> &vst) {
    if (vst[u]) return;

    vst[u] = true;
    for (int v : adj_list[u]) {
        if (v == parent) continue;
        // If the longest path of parent goes through child, use down2
        if (down1[u] == down1[v] + 1) {
            up[v] = max(up[u], down2[u]) + 1;
        } else {
            up[v] = max(up[u], down1[u]) + 1;
        }
        dfs2(v, u, vst);
    }
}

vector<int> computeLongestPaths(int n, vector<int> &longest_path_of_island) {
    down1.assign(n + 1, 0);
    down2.assign(n + 1, 0);
    up.assign(n + 1, 0);

    vector<bool> vst1(n + 1), vst2(n + 1);
    for (int u = 1; u <= n; u++) {
        dfs1(u, 0, vst1);
        dfs2(u, 0, vst2);
    }

    vector<int> longest_path_from(n + 1);
    for (int u = 1; u <= n; u++) {
        longest_path_from[u] = max(down1[u], up[u]) + 1;
        longest_path_of_island[island_of[u]] = max(
            longest_path_of_island[island_of[u]],
            longest_path_from[u]
        );
    }
    return longest_path_from;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    adj_list.resize(n + 1);
    for (int i = 0; i < n - 3; i++) {
        int u, v; cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int island = 0;
    vector<bool> vst(n + 1);
    island_of.resize(n + 1);
    for (int u = 1; u <= n; u++) {
        if (vst[u]) continue;

        visit(u, 0, vst, island);
        island++;
    }

    vector<int> longest_path_of_island(3);
    vector<int> longest_path_from = computeLongestPaths(n, longest_path_of_island);
    while (q--) {
        int u, v; cin >> u >> v;
        int ans = longest_path_from[u] + longest_path_from[v];
        for (island = 0; island < 3; island++)
        if (island != island_of[u] && island != island_of[v])
            ans += longest_path_of_island[island];
    
        cout << ans << "\n";
    }

    return 0;
}
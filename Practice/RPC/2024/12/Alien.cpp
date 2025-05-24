#include <bits/stdc++.h>
using namespace std;

int count_nodes(int node, vector<vector<int>> &adj_list, vector<bool> &vst) {
    if (vst[node]) return 0;
    
    vst[node] = true;

    int sum = 0;
    for (int &f : adj_list[node])
        sum += count_nodes(f, adj_list, vst);

    return sum + 1;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj_list(n + 1);
    vector<bool> vst(n + 1, false);
    
    int u, v;
    while (m--) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int maxi = 0;
    for (int i = 1; i <= n; i++)
        maxi = max(maxi, count_nodes(i, adj_list, vst));
    
    cout << maxi << endl;

    return 0;
}
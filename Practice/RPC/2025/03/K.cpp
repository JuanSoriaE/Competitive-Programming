#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> &e, vector<bool> &vst) {
    if (vst[node]) return 0;
    vst[node] = true;
    return dfs(e[node], e, vst) + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> e(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> e[i];

    vector<bool> vst(n + 1);
    cout << dfs(1, e, vst) << "\n";

    return 0;
}
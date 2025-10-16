// https://codeforces.com/contest/510/problem/C
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

int n;
vector<string> names;
vector<uset<int>> adj(26);

pair<bool, vector<int>> topo_sort() {
    vector<int> in_degree(26, 0);
    for (int u = 0; u < 26; u++)
    for (int v : adj[u]) in_degree[v]++;

    queue<int> q;
    for (int u = 0; u < 26; u++)
    if (in_degree[u] == 0) q.push(u);

    vector<int> order(26);
    int i = 0, visited = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order[i++] = u;
        visited++;

        for (int v : adj[u])
        if (--in_degree[v] == 0)
            q.push(v);
    }

    return {visited == 26, order};
}

string solve() {
    for (int i = 0; i < n - 1; i++) {
        string &s = names[i], &t = names[i + 1];
        for (int j = 0; j < sz(s); j++) {
            if (j >= sz(t)) return "Impossible";
            if (s[j] == t[j]) continue;

            adj[s[j] - 'a'].insert(t[j] - 'a');
            break;
        }
    }

    auto [valid, order] = topo_sort();
    if (!valid) return "Impossible";

    string ans = "";
    for (int i : order)
        ans += ((char)('a' + i));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    names.resize(n);
    for (int i = 0; i < n; i++) cin >> names[i];

    cout << solve() << "\n";
    return 0;
}
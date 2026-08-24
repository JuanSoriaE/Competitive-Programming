#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    vector<bool> used(3 * n + 1);

    vector<int> matching;
    for (int i = 0; i < m; i++) {
        auto &[u, v] = edges[i];
        cin >> u >> v;

        if (!used[u] && !used[v]) {
            matching.push_back(i + 1);
            used[u] = used[v] = true;
        }
    }

    if (sz(matching) >= n) {
        cout << "Matching\n";
        for (int i = 0; i < n; i++)
            cout << matching[i] << ' ';
    } else {
        cout << "IndSet\n";
        for (int i = 1, cnt = 0; cnt < n; i++)
        if (!used[i]) {
            cout << i << ' ';
            cnt++;
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
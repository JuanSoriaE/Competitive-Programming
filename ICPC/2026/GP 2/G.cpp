#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100000

int p[MAX_N], _size[MAX_N];

int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;

    if (_size[a] > _size[b]) swap(a, b);
    p[a] = b;
    _size[b] += _size[a];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    iota(p, p + n, 0); fill(_size, _size + n, 1);

    while (m--) {
        int u, v; cin >> u >> v;
        unite(u, v);
    }

    vector<vector<int>> components(n);
    for (int i = 0; i < n; i++)
        components[find(i)].push_back(i);

    // size, p
    set<pair<int, int>, greater<pair<int, int>>> st;
    for (int i = 0; i < n; i++) {
        if (!components[i].empty())
            st.insert({sz(components[i]), i});
    }
    
    vector<pair<int, int>> ans;
    while (sz(st) > 1) {
        auto it1 = st.begin(),
             it2 = next(it1);

        auto [sz1, p1] = *it1;
        auto [sz2, p2] = *it2;

        ans.push_back({
            components[p1][sz(components[p1]) - sz1],
            components[p2][sz(components[p2]) - sz2],
        });

        st.erase(it1); st.erase(it2);
        if (sz1 > 1) st.insert({sz1 - 1, p1});
        if (sz2 > 1) st.insert({sz2 - 1, p2});
    }

    cout << sz(ans) << '\n';
    for (auto &[a, b] : ans)
        cout << a << ' ' << b << '\n';

    return 0;
}
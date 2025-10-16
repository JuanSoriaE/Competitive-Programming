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

vector<ll> v;

struct DSU {
    vector<int> p, size;
    vector<ll> sum;
    ll max_sum;
    DSU(int n) : p(n), size(n, 1), sum(n) { for (int i = 0; i < n; i++) { p[i] = i; sum[i] = v[i]; } max_sum = 0; }
    int find(int a) { return p[a] == a ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        sum[b] += sum[a];
        max_sum = max(max_sum, sum[b]);
        return 1;
    }
    void undestroy(int a) {
        max_sum = max(max_sum, v[a]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<bool> destroyed(n, true);

    vector<int> queries(n);
    int index;
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
        queries[i]--;
    }

    DSU dsu(n);
    vector<ll> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = dsu.max_sum;
        dsu.undestroy(queries[i]);

        if (queries[i] - 1 >= 0 && !destroyed[queries[i] - 1])
            dsu.unite(queries[i], queries[i] - 1);
        if (queries[i] + 1 < n && !destroyed[queries[i] + 1])
            dsu.unite(queries[i], queries[i] + 1);

        destroyed[queries[i]] = 0;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";

    return 0;
}
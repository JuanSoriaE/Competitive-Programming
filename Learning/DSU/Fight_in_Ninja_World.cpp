// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/containers-of-choclates-1/
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
#define fst first
#define snd second

struct DSU {
    vector<int> p, size, len;
    DSU(int n) : p(n, -1), size(n, 1), len(n, 0) {}

    pair<int, int> find(int a) {
        if (p[a] == -1) p[a] = a;
        if (a == p[a]) return {a, 0};
        const auto [pa, la] = find(p[a]);
        p[a] = pa;
        len[a] = (len[a] + la) % 2;
        return {p[a], len[a]};
    }
    bool unite(int a, int b) {
        auto [pa, la] = find(a);
        auto [pb, lb] = find(b);
        if (pa == pb) return 0;

        if (size[pa] > size[pb]) {
            swap(pa, pb);
            swap(la, lb);
        }
        p[pa] = pb;
        size[pb] += size[pa];
        len[pa] = (la + lb + 1) % 2;
        return 1;
    }
    vector<vector<pair<int, int>>> get_sets() {
        vector<vector<pair<int, int>>> sets(sz(p));
        for (int i = 0; i < sz(p); i++)
        if (p[i] != -1)
            sets[find(i).fst].push_back({i, len[i]});
        return sets;
    }
};

int solve() {
    int n; cin >> n;
    int u, v;
    DSU dsu(2 * 10000);
    while (n--) {
        cin >> u >> v;
        u--; v--;
        dsu.unite(u, v);
    }

    int ans = 0;
    for (const auto &set : dsu.get_sets()) {
        int cnt[2] = {0};
        for (const auto &[a, l] : set)
            cnt[l]++;
        ans += max(cnt[0], cnt[1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case " << i << ": " << solve() << "\n";
    return 0;
}
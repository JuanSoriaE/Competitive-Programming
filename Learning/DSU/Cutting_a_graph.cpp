// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
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
    DSU(int n) : p(n), size(n, 1) { iota(all(p), 0); }

    int find(int a) { return a == p[a] ? a : (p[a] = find(p[a])); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        return 1;
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    int u, v;
    while (m--) cin >> u >> v;

    //          cut
    vector<pair<bool, pair<int, int>>> op(k);
    int ask_cnt = 0;
    string s;
    for (int i = k - 1; i >= 0; i--) {
        cin >> s;
        op[i].first = s == "cut";
        cin >> op[i].second.first >> op[i].second.second;
        ask_cnt += !op[i].first;
    }

    DSU dsu(n + 1);
    //     connected
    vector<bool> ans(ask_cnt);
    int j = ask_cnt - 1;
    for (int i = 0; i < k; i++) {
        if (op[i].first) // cut
            dsu.unite(op[i].second.first, op[i].second.second);
        else
            ans[j--] = dsu.same_set(op[i].second.first, op[i].second.second);
    }

    for (int i = 0; i < ask_cnt; i++)
        cout << (ans[i] ? "YES" : "NO") << "\n";
    return 0;
}
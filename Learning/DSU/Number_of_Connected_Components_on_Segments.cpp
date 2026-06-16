#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define pii pair<int, int>

#define MAX_M 50000
#define MAX_K 50000
#define BLOCK_SIZE 224

struct DSU {
    vector<int> p, size;
    stack<array<int, 5>> ops;
    int sets, version;
    DSU(int n) : p(n), size(n, 1), sets(n), version(0) { iota(all(p), 0); }

    int find(int a) { while(p[a] != a) a = p[a]; return a; }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;

        if (size[a] > size[b]) swap(a, b);
        ops.push({version, a, b, p[a], size[a]});
        p[a] = b; size[b] += size[a];
        sets--;
    }
    void checkpoint() { version++; }
    void rollback() {
        while (!ops.empty() && ops.top()[0] == version) {
            auto [v, a, b, pa, sa] = ops.top(); ops.pop();
            p[a] = a; size[b] -= sa;
            sets++;
        }
        version = max(0, version - 1);
    }
};

pair<int, int> edges[MAX_M];
vector<array<int, 3>> blocks[BLOCK_SIZE];
int ans[MAX_K];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; edges[i].second--;
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        blocks[l / BLOCK_SIZE].push_back({l - 1, r - 1, i});
    }

    auto comp = [](const array<int, 3> &q1, const array<int, 3> &q2) {
        return q1[1] < q2[1];
    };
    for (int i = 0; i < BLOCK_SIZE; i++)
        sort(all(blocks[i]), comp);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        int block_s = i * BLOCK_SIZE, block_e = (i + 1) * BLOCK_SIZE - 1;
        DSU dsu(n);
        int last_r = block_e;
        for (auto &[l, r, query_i] : blocks[i]) {
            if (r <= block_e) {
                for (int j = l; j <= r; j++)
                    dsu.unite(edges[j].first, edges[j].second);
            } else {
                for (int j = last_r + 1; j <= r; j++)
                    dsu.unite(edges[j].first, edges[j].second);
                dsu.checkpoint();
                for (int j = l; j <= block_e; j++)
                    dsu.unite(edges[j].first, edges[j].second);
                last_r = r;
            }
            ans[query_i] = dsu.sets;
            dsu.rollback();
        }
    }

    for (int i = 0; i < k; i++)
        cout << ans[i] << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// Persistent DSU with Rollback
struct DSU {
    vector<int> p, size;
    stack<array<int, 5>> ops;
    int version;
    DSU(int n) : p(n), size(n, 1), version(0) { iota(all(p), 0); }

    int find(int a) { while (p[a] != a) a = p[a]; return a; }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;

        if (size[a] > size[b]) swap(a, b);
        ops.push({version, a, b, p[a], size[a]});
        p[a] = b;
        size[b] += size[a];
        return 1;
    }
    void checkpoint() { version++; }
    void rollback() {
        while (!ops.empty() && ops.top()[0] == version) {
            auto [v, a, b, pa, sa] = ops.top(); ops.pop();
            p[a] = pa;
            size[b] -= sa;
        }
        version = max(version - 1, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
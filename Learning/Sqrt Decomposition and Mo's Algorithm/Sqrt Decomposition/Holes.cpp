// https://codeforces.com/problemset/problem/13/E
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

struct Sqrt {
    int n, block_size;
    vector<int> a, next, jumps;

    Sqrt(vector<int> &a) : n(sz(a)), a(a), block_size(sqrt(n) + 1), next(n, -1), jumps(n) {
        for (int i = block_size - 1; i < n; i += block_size)
            update(i, a[i]);
        update(n - 1, a[n - 1]);
    };

    void update(int i, int x) {
        a[i] = x;
        int block_id = i / block_size, block_start = block_id * block_size;
        while (i >= block_start) {
            int next_pos = i + a[i];
            if (block_id == next_pos / block_size) {
                next[i] = (next_pos < n ? next[next_pos] : n);
                jumps[i] = (next_pos < n ? jumps[next_pos] : 0) + 1;
            } else {
                next[i] = next_pos;
                jumps[i] = 1;
            }
            i--;
        }
    }
    pair<int, int> query(int i) {
        int last, _jumps = 0;
        while (i < n) {
            last = i;
            _jumps += jumps[i];
            i = next[i];
        }
        i = last;
        while (i < n) {
            last = i;
            i += a[i];
        }
        return {last, _jumps};
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n); for (int &i : a) cin >> i;

    Sqrt sqrt_dec(a);
    while (m--) {
        int type; cin >> type;
        if (type == 0) {
            int a, b; cin >> a >> b;
            sqrt_dec.update(--a, b);
        } else {
            int a; cin >> a;
            auto [last, jumps] = sqrt_dec.query(--a);
            cout << (last + 1) << " " << jumps << "\n";
        }
    }
    return 0;
}
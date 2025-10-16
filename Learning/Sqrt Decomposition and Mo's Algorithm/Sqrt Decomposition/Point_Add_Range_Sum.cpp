// https://judge.yosupo.jp/problem/point_add_range_sum
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
    int block_size;
    vector<ll> a, b;

    Sqrt(vector<ll> &a) : block_size(sqrt(sz(a)) + 1), a(a), b(block_size) {
        for (int i = 0; i < sz(a); i++) b[i / block_size] += a[i];
    };

    void update(int i, int x) {
        int id = i / block_size;
        b[id] += x;
        a[i] += x;
    }
    ll query(int l, int r) {
        ll res = 0;
        while (l <= r && l % block_size != 0)
            res += a[l++];
        while (l + block_size - 1 <= r)
            res += b[l / block_size], l += block_size;
        while (l <= r)
            res += a[l++];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<ll> a(n); for (ll &i : a) cin >> i;

    Sqrt sqrt_dec(a);
    while (q--) {
        int type, a, b; cin >> type >> a >> b;
        if (type == 0)
            sqrt_dec.update(a, b);
        else
            cout << sqrt_dec.query(a, --b) << "\n";
    }

    return 0;
}
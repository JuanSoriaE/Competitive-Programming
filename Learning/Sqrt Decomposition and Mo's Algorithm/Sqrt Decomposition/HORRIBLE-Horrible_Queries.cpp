// https://www.spoj.com/problems/HORRIBLE/
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
    const int BLOCK_SIZE = 317;
    vector<ll> a, sum, add;

    Sqrt(int n) : a(n, 0),
        sum(BLOCK_SIZE, 0), add(BLOCK_SIZE, 0) {};

    void update(int l, int r, ll x) {
        while (l <= r && l % BLOCK_SIZE != 0)
            sum[l / BLOCK_SIZE] += x, a[l] += x, l++;
        while (l + BLOCK_SIZE - 1 <= r)
            sum[l /BLOCK_SIZE] += x * BLOCK_SIZE, add[l / BLOCK_SIZE] += x, l += BLOCK_SIZE;
        while (l <= r)
            sum[l / BLOCK_SIZE] += x, a[l] += x, l++;
    }
    ll query(int l, int r) {
        ll res = 0;
        while (l <= r && l % BLOCK_SIZE != 0)
            res += a[l] + add[l / BLOCK_SIZE], l++;
        while (l + BLOCK_SIZE - 1 <= r)
            res += sum[l / BLOCK_SIZE], l += BLOCK_SIZE;
        while (l <= r)
            res += a[l] + add[l / BLOCK_SIZE], l++;
        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    Sqrt sqrt_dec(n);
    while (q--) {
        int type, l, r; cin >> type >> l >> r;
        l--; r--;

        if (type == 0) {
            int v; cin >> v;
            sqrt_dec.update(l, r, v);
        } else
            cout << sqrt_dec.query(l, r) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(const int &n) : n(n), bit(n) {}

    void update(int i, int delta) {
        for (; i < n; i = i | (i + 1))
            bit[i] += delta;
    }
    int query(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    FenwickTree f(n + 1);
    ll inv_f = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        inv_f += f.query(p - 1);
        f.update(p, 1);
    }

    ll inv_i = (ll)(n - 1) * n / 2;
    ll delta = inv_i - inv_f;
    if (n & 1)
        cout << (delta & 1 ? "Petr" : "Um_nik") << '\n';
    else
        cout << (delta & 1 ? "Um_nik" : "Petr") << '\n';

    return 0;
}
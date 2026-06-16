// https://www.spoj.com/problems/TRIPINV/
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

template<typename T>
struct FenwickTree {
    vector<T> bit;
    int n;

    FenwickTree(const int &n) : n(n), bit(n) {}
    FenwickTree(const vector<T> &a) : n(sz(a)), bit(n) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    void update(int i, T delta) {
        for (; i < n; i = i | (i + 1))
            bit[i] += delta;
    }
    T query(int r) {
        T ret = T();
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void clear() {
        bit.assign(n, T());
    }
};

int a[MAX_N];
int greater_l[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    FenwickTree<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        greater_l[i] = f.query(a[i] + 1, n);
        f.update(a[i], 1);
    }

    reverse(a, a + n);
    f.clear();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += static_cast<ll>(greater_l[n - 1 - i]) * f.query(a[i] - 1);
        f.update(a[i], 1);
    }
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 200000

struct Data {
    ll in, out, in_rev, out_rev;
    Data() : in(0), out(0), in_rev(0), out_rev(0) {}
    Data(const ll &in, const ll &out, const ll &in_rev, const ll &out_rev) :
        in(in), out(out), in_rev(in_rev), out_rev(out_rev) {}

    Data operator+(const Data &o) const {
        return Data(in + o.in, out + o.out, in_rev + o.in_rev, out_rev + o.out_rev); 
    }
    Data operator-(const Data &o) const {
        return Data(in - o.in, out - o.out, in_rev - o.in_rev, out_rev - o.out_rev); 
    }
};

template<typename T>
struct FenwickTree {
    int n;
    vector<T> bit;

    FenwickTree(const int &n) : n(n), bit(n, 0) {}
    FenwickTree(const vector<T> &a) : n(sz(a)), bit(n) {
        for (int i = 0; i < n; i++) {
            bit[i] = bit[i] + a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] = bit[r] + bit[i];
        }
    }

    void update(int i, T delta) {
        for (; i < n; i = i | (i + 1))
            bit[i] = bit[i] + delta;
    }
    T query(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = ret + bit[r];
        return ret;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int p[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;

    FenwickTree<int> f1(n + 1);
    vector<Data> data(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        int smaller_l = f1.query(p[i]), greater_l = i - smaller_l,
            smaller_r = p[i] - 1 - smaller_l, greater_r = n - p[i] - greater_l;
        data[i] = {greater_l, smaller_r, greater_r, smaller_l};
        f1.update(p[i], 1);
        total += greater_l;
    }

    FenwickTree<Data> f(data);
    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            Data d_i = f.query(x - 1, x - 1), d_i_1 = f.query(x, x);
            Data new_d_i = d_i_1, new_d_i_1 = d_i;

            if (p[x - 1] > p[x]) {
                new_d_i.in--;
                new_d_i_1.out--;
                new_d_i.in_rev++;
                new_d_i_1.out_rev++;
                total--;
            } else {
                new_d_i_1.in++;
                new_d_i.out++;
                new_d_i_1.in_rev--;
                new_d_i.out_rev--;
                total++;
            }

            swap(p[x - 1], p[x]);
            f.update(x - 1, new_d_i - d_i);
            f.update(x, new_d_i_1 - d_i_1);
        } else {
            Data A = f.query(x - 1), B = f.query(x, n - 1);
            ll ans = total - (A.out - A.in) + (B.out_rev - B.in_rev);
            cout << ans << '\n';
        }
    }
    return 0;
}
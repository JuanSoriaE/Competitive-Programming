#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

template<typename T>
struct FenwickTree {
    int n;
    vector<T> bit;

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
};

int get_real_index(int x, const int &n, FenwickTree<int> &ft) {
    int l = 0, r = n - 1, res;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int pref = ft.query(m - 1);
        if (m - pref == x)
            res = m, l = m + 1;
        else if (m - pref < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n / 2), b(n / 2);
    for (int &i : a) { cin >> i; i--; }
    for (int &i : b) { cin >> i; i--; }

    FenwickTree<int> ft(n);
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int index = a[i / 2];
            int real_index = get_real_index(index, n, ft);
            ft.update(real_index, 1);
            x.push_back(real_index);
        } else {
            int index = b[i / 2];
            int real_index = get_real_index(index, n, ft);
            ft.update(real_index, 1);
            y.push_back(real_index);
        }
    }

    for (int &i : x) cout << i + 1 << ' ';
    cout << '\n';
    for (int &i : y) cout << i + 1 << ' ';
    cout << '\n';

    return 0;
}
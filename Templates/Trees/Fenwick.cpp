#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

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
};

template<typename T>
struct FenwickTree2D {
    vector<vector<T>> bit;
    int n, m;

    FenwickTree2D(const int &n, const int &m) : n(n), m(m), bit(n, vector<T>(m)) {}

    T update(int r, int c, T delta) {
        for (int i = r; i < n; i = i | (i + 1))
        for (int j = c; j < m; j = j | (j + 1))
            bit[i][c] += delta;
    }
    T query(int r, int c) {
        T ret = T();
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit[r][c];
        return ret;
    }
    T query(int r1, int c1, int r2, int c2) {
        return  query(r2, c2) - query(r2, c1 - 1) - query(r1 - 1, c2) + query(r1 - 1, c1 - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// Sparse Table
constexpr int MAX_N = 1000000;
constexpr int K = 25; // K >= floor(log2(n))

template<typename T>
struct SparseTable {
    int n;
    T st[K + 1][MAX_N];

    SparseTable(const vector<T> &a) : n(sz(a)) {
        copy(all(a), st[0]);
        for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    T f(T &a, T &b) { return a + b; } // Change the function accordingly
    T query(int l, int r) { // non-idempotent functions
        T res = T();
        for (int i = K; i >= 0; i--)
        if ((1 << i) <= r - l + 1)
            res = f(res, st[i][l]), l += 1 << i;
        return res;
    }
    T query(int l, int r) { // idempotent functions
        int i = log2_floor(r - l + 1);
        return f(st[i][l], st[i][r - (1 << i) + 1]);
    }
    int log2_floor(int n) { return 31 - __builtin_clz(n); }
};

// Sparse Table 2D
constexpr int K = 10, L = 10; // K >= floor(log2(n)) | L >= floor(log2(m))
constexpr int MAX_N = 1000, MAX_M = 1000;

template<typename T>
struct SparseTable2D {
    int n, m;
    T st[MAX_N][MAX_M][K + 1][L + 1];

    SparseTable2D(const vector<vector<T>> &a) : n(sz(a)), m(sz(a[0])) {
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            st[i][j][0][0] = a[i][j];

        for (int k = 1; k <= K; k++)
        for (int i = 0; i + (1 << k) <= n; i++)
        for (int j = 0; j < m; j++)
            st[i][j][k][0] = f(st[i][j][k - 1][0],
                st[i + (1 << (k - 1))][j][k - 1][0]);

        for (int l = 1; l <= L; l++)
        for (int i = 0; i < n; i++)
        for (int j = 0; j + (1 << l) <= m; j++)
            st[i][j][0][l] = f(st[i][j][0][l - 1],
                st[i][j + (1 << (l - 1))][0][l - 1]);

        for (int k = 1; k <= K; k++)
        for (int l = 1; l <= L; l++)
        for (int i = 0; i + (1 << k) <= n; i++)
        for (int j = 0; j + (1 << l) <= m; j++)
            st[i][j][k][l] = f(
                f(st[i][j][k - 1][l - 1],
                    st[i + (1 << (k - 1))][j][k - 1][l - 1]),
                f(st[i][j + (1 << (l - 1))][k - 1][l - 1],
                    st[i + (1 << (k - 1))][j + (1 << (l - 1))][k - 1][l - 1])
            );
    }
    T f(T a, T b) { return min(a, b); }
    T query(int r1, int c1, int r2, int c2) {
        int k = log2_floor(r2 - r1 + 1);
        int l = log2_floor(c2 - c1 + 1);
        return f(
            f(st[r1][c1][k][l], st[r2 - (1 << k) + 1][c1][k][l]),
            f(st[r1][c2 - (1 << l) + 1][k][l],
                st[r2 - (1 << k) + 1][c2 - (1 << l) + 1][k][l])
        );
    }
    int log2_floor(int n) { return 31 - __builtin_clz(n); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}

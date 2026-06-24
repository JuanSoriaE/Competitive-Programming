// https://codeforces.com/contest/713/problem/D
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int K = 10, L = 10; // K >= floor(log2(n)) | L >= floor(log2(m))
constexpr int MAX_N = 1000, MAX_M = 1000;

int n, m;
short mat[MAX_N + 1][MAX_M + 1];

template<typename T>
struct SparseTable2D {
    int n, m;
    T st[MAX_N][MAX_M][K + 1][L + 1];

    SparseTable2D(int n, int m) : n(n), m(m) {
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            st[i][j][0][0] = mat[i][j];

        for (int k = 1; k <= K; k++)
        for (int i = 0; i + (1 << k) <= n; i++)
        for (int j = 0; j < m; j++)
            st[i][j][k][0] = f(st[i][j][k - 1][0], st[i + (1 << (k - 1))][j][k - 1][0]);

        for (int l = 1; l <= L; l++)
        for (int i = 0; i < n; i++)
        for (int j = 0; j + (1 << l) <= m; j++)
            st[i][j][0][l] = f(st[i][j][0][l - 1], st[i][j + (1 << (l - 1))][0][l - 1]);

        for (int k = 1; k <= K; k++)
        for (int l = 1; l <= L; l++)
        for (int i = 0; i + (1 << k) <= n; i++)
        for (int j = 0; j + (1 << l) <= m; j++)
            st[i][j][k][l] = f(
                f(st[i][j][k - 1][l - 1], st[i + (1 << (k - 1))][j][k - 1][l - 1]),
                f(st[i][j + (1 << (l - 1))][k - 1][l - 1],
                    st[i + (1 << (k - 1))][j + (1 << (l - 1))][k - 1][l - 1])
            );
    }
    T f(T a, T b) { return max(a, b); }
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

unique_ptr<SparseTable2D<short>> st;

short solve() {
    int r1, c1,  r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    int l = 0, r = min(r2 - r1 + 1, c2 - c1 + 1);

    short res;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        int row = r2 - mid + 1, col = c2 - mid + 1;
        if (st->query(r1, c1, row, col) >= mid) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> mat[i][j];

    for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--) {
        if (!mat[i][j]) continue;
        short min_posible = min(mat[i][j + 1], mat[i + 1][j]);
        mat[i][j] = min_posible + min(mat[i + min_posible][j + min_posible], (short)1);
    }

    st = make_unique<SparseTable2D<short>>(n, m);

    int q; cin >> q;
    while (q--)
        cout << solve() << '\n';

    return 0;
}
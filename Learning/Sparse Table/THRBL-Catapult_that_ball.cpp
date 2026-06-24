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
struct SparseTable {
    const int K = 25; // K >= floor(log2(MAX_N))
    int n;
    vector<vector<T>> st;
    
    SparseTable(const vector<T> &a) : n(sz(a)), st(K + 1, vector<T>(n)) {
        copy(all(a), st[0].begin());
        for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    T f(T &a, T &b) { return max(a, b); } // Change the function accordingly
    T query(int l, int r) { // idempotent functions
        int i = log2_floor(r - l + 1);
        return f(st[i][l], st[i][r - (1 << i) + 1]);
    }
    int log2_floor(int n) { return 31 - __builtin_clz(n); }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    SparseTable<int> st(a);
    int ans = 0;
    while (m--) {
        int l, r; cin >> l >> r;
        l--, r--;
        if (st.query(l, r - 1) == a[l])
            ans++;
    }
    cout << ans << '\n';

    return 0;
}
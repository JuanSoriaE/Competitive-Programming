#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define mat vector<vector<ll>>
#define MOD 1000000007

mat mult_mat(mat &m1, mat &m2) {
    const int R = sz(m1), C = sz(m1[0]);
    const int r = sz(m2), c = sz(m2[0]);

    mat res(R, vector<ll>(c));
    for (int i = 0; i < R; i++)
    for (int j = 0; j < c; j++)
    for (int k = 0; k < C; k++)
        res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;

    return res;
}

mat bin_pow(mat m, ll b) {
    const int N = sz(m);
    mat res(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) res[i][i] = 1;

    while (b) {
        if (b & 1)
            res = mult_mat(res, m);
        m = mult_mat(m, m);
        b >>= 1;
    }

    return res;
}

void print_mat(mat &m) { for (int i = 0; i < sz(m); i++) {
    for (int j = 0; j < sz(m[0]); j++) cout << m[i][j] << ' ';
    cout << endl;
} }

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll n; cin >> n;
    mat m(45, vector<ll>(45, 0));
    m[0][9] = 16;
    m[0][19] = 9;
    m[0][29] = 4;
    m[0][39] = 1;
    for (int i = 1; i < 45; i++)
        m[i][i - 1] = 1;

    m = bin_pow(m, n);

    mat v(45, vector<ll>(1, 0));
    v[0][0] = 1;

    v = mult_mat(m, v);

    ll ans = 0;
    for (int i = 0; i < 45; i++)
        ans = (ans + v[i][0]) % MOD;
    cout << ans << '\n';

    return 0;
}
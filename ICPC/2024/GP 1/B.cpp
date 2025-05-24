#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define uset unordered_set
#define umap unordered_map

#define MOD 1000000007

vector<vector<ll>> mult_mat(vector<vector<ll>> &m1, vector<vector<ll>> &m2) {
    int R = sz(m1), C = sz(m1[0]);
    int r = sz(m2), c = sz(m2[0]);
    if (C != r) return {};

    vector<vector<ll>> res(R, vector<ll>(c));
    for (int i = 0; i < R; i++)
    for (int j = 0; j < c; j++)
    for (int k = 0; k < C; k++)
        res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
    
    return res;
}

// Binary Exponentiation (Matrix)
vector<vector<ll>> bin_pow(vector<vector<ll>> m, ll b) {
    int N = sz(m);
    vector<vector<ll>> res(N, vector<ll>(N));
    for (int i = 0; i < N; i++) res[i][i] = 1;
    
    while (b) {
        if (b & 1)
            res = mult_mat(res, m);
        m = mult_mat(m, m);
        b >>= 1;
    }
    return res;
}

void print_m(vector<vector<ll>> &m) { for (int i = 0; i < sz(m); i++) { for (int j = 0; j < sz(m[0]); j++) cout << m[i][j] << " "; cout << "\n"; }}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    vector<vector<ll>> m(20, vector<ll>(20, 0));
    m[0][5] = 3;
    m[0][9] = 3;
    m[0][13] = 3;
    m[0][17] = 3;
    for (int i = 1; i <= 19; i++)
        m[i][i - 1] = 1;

    vector<vector<ll>> v_0(20, vector<ll>(1, 0));
    v_0[0][0] = 1;
    
    while (t--) {
        ll n; cin >> n;
        vector<vector<ll>> m_pow = bin_pow(m, n);
        vector<vector<ll>> v_n = mult_mat(m_pow, v_0);
        
        ll ans = 0;
        for (int i = 0; i < sz(v_n); i++)
            ans = (ans + v_n[i][0]) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MOD 1000000007

vector<vector<ll>> mult_mat(vector<vector<ll>> &m1, vector<vector<ll>> &m2) {
    const int R = sz(m1), C = sz(m1[0]);
    const int r = sz(m2), c = sz(m2[0]);

    vector<vector<ll>> res(R, vector<ll>(c));
    for (int i = 0; i < R; i++)
    for (int j = 0; j < c; j++)
    for (int k = 0; k < C; k++)
        res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;

    return res;
}

vector<vector<ll>> bin_pow(vector<vector<ll>> m, int b) {
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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<ll>> m = {
        {0, 3},
        {1, 2}
    };
    
    cout << bin_pow(m, n)[0][0] << '\n';
    return 0;
}
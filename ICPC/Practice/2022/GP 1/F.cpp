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
#define MAX_M 1000000
#define MAX_MEMO 1000000

int holes[MAX_M + 2];
mat memo[MAX_MEMO + 1];
bool memo_flag[MAX_MEMO + 1];

mat mult_mat(mat &m1, mat &m2) {
    const int N = 2;
    mat res(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    for (int k = 0; k < N; k++)
        res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
    return res;
}

mat bin_pow(mat m, int b) {
    if (b == 0)
        return {{1, 0}, {0, 1}};
    if (b < MAX_MEMO && memo_flag[b])
        return memo[b];

    mat half = bin_pow(m, b / 2);
    mat mult = mult_mat(half, half);
    mat ret = b & 1 ? mult_mat(mult, m) : mult;

    if (b < MAX_MEMO) {
        memo_flag[b] = true;
        memo[b] = ret;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;

    holes[0] = -1; holes[m + 1] = n + 1;
    for (int i = 1; i <= m; i++)
        cin >> holes[i];

    sort(holes + 1, holes + m + 1);

    ll ans = 1;
    mat tran_m = {{0, 1}, {1, 1}};
    for (int i = 1; i <= m + 1; i++) {
        int length = holes[i] - holes[i - 1] - 1;
        if (!length) {
            cout << "0\n";
            return 0;
        }

        ans = (ans * bin_pow(tran_m, length - 1)[1][1]) % MOD;
    }
    cout << ans << '\n';

    return 0;
}
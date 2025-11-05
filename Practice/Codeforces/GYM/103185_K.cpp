#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

#define MOD 1000000007
#define MAX_K 750
#define MAX_N 1000

int mat[MAX_K][MAX_K];
ll dp[MAX_K];
ll aux[MAX_K + 1];

int k;

int get_l(int row, int x) {
    int l = 0, r = k;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mat[row][mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int get_r(int row, int x) {
    int l = 0, r = k;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mat[row][mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return l - 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int L; cin >> k >> L;
    for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++)
        cin >> mat[i][j];

    fill(dp, dp + k, 1);

    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int gap; cin >> gap;
        fill(aux, aux + k, 0);
        for (int row = 0; row < k; row++) {
            int l = get_l(row, gap - L), r = get_r(row, gap + L);
            if (l > r) continue;

            aux[l] = (aux[l] + dp[row]) % MOD;
            aux[r + 1] = (aux[r + 1] - dp[row] + MOD) % MOD;
        }

        fill(dp, dp + k, 0);
        dp[0] = aux[0];
        for (int j = 1; j < k; j++)
        dp[j] = (dp[j - 1] + aux[j]) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < k; i++)
    ans = (ans + dp[i]) % MOD;
    cout << ans << '\n';

    return 0;
}
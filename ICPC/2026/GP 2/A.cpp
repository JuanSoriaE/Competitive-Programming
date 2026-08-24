#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MOD = 998244353;
constexpr int MAX_N = 2000;
constexpr int MAX_K = 2000;

int lps[MAX_N];
ll dp[MAX_K + 1][MAX_N];

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }

    for (int placed = 0; placed <= k; placed++)
        fill(dp[placed], dp[placed] + n, 0);
    dp[0][0] = 1;

    for (int placed = 0; placed < k; placed++)
    for (int i = 0; i < n; i++)
    for (char c = 'a'; c <= 'z'; c++) {
        int j = i;
        while (j && s[j] != c)
            j = lps[j - 1];
        if (s[j] == c)
            j++;
        dp[placed + 1][j] = (dp[placed][i] + dp[placed + 1][j]) % MOD;
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout << dp[k][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
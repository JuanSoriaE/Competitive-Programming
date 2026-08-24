#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<ld> x(n + 1), p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> p[i] >> q[i];

    vector<ld> dp(n + 1), ans(n + 1);
    for (int k = 1; k <= n; k++) {
        for (int i = n; i >= k; i--) {
            dp[i] = dp[i - 1] + x[i] * (p[i] * k) / q[i];
            ans[k] = max(ans[k], dp[i]);
        }
        for (int i = k; i <= n; i++)
            dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << setprecision(50);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
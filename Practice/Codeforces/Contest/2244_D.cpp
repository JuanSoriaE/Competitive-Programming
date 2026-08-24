#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;
constexpr int MAX_M = 200000;

int a[MAX_N + 1], b[MAX_M + 1];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(b + 1, b + m + 1);

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ll sum = 0;
        for (int j = b[i - 1] + 1; j <= b[i]; j++)
            sum += a[j];
        ans += abs(sum);
    }

    for (int i = b[m] + 1; i <= n; i++)
        ans += a[i];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
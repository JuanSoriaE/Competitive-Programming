#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

void solve() {
    ll x, y, k; cin >> x >> y >> k;
    ll ans = 0, i = 0, d = y - x;
    for (; i < k; i++) {
        if (x > d) break;
        ans += y % x;
        x++, y++;
    }

    ans += i == k ? 0LL : (k - i) * d;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
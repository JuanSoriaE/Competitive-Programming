#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

ll f(ll i) {
    return 4LL * i * i + 2LL * i;
}

void solve() {
    ll a; cin >> a;
    int l = 0, r = 499999, i;
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (f(m) <= a)
            i = m, l = m + 1;
        else
            r = m - 1;
    }

    a -= f(i);
    ll x = -i, y = -i;
    ll inc = 2LL * i + 1LL;

    x += min(a, inc);
    a -= min(a, inc);
    y += min(a, inc);
    a -= min(a, inc);

    inc++;

    x -= min(a, inc);
    a -= min(a, inc);
    y -= min(a, inc);
    a -= min(a, inc);

    ll ans = (x * 2LL) * (x * 2LL) + (y * 2LL) * (y * 2LL);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
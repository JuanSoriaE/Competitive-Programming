#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

bool valid(int m, int a, int b, int c) {
    if (a > m && c > m) return false;

    if (a < m) {
        int extra = m - a;
        a += min(b, extra);
        b -= min(b, extra);
    }
    if (c < m) {
        int extra = m - c;
        c += min(b, extra);
        b -= min(b, extra);
    }

    bool a_in_b = false;
    if (a > m) {
        if (b >= m) return false;
        int extra = m - b;
        if (a - m > extra) return false;
        a_in_b = true;
        b += a - m;
    }
    if (c > m) {
        if (a_in_b) return false;
        if (b >= m) return false;
        int extra = m - b;
        if (c - m > extra) return false;
        b += b - m;
    }

    if (b > m) {
        int extra = max(0, m - a) + max(0, m - c);
        if (b - m > extra) return false;
    }

    return true;
}

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int l = 1, r = a + b + c, ans;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (valid(m, a, b, c)) {
            ans = m; r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
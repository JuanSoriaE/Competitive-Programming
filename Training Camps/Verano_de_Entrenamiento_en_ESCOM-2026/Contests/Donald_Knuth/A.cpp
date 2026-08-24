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
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    ll prefix = 0;
    bool valid = true;
    for (int i = 0; i < n && valid; i++) {
        if (prefix + 1 > 1e9) valid = false;

        if (a[i] == -1) {
            a[i] = prefix + 1;
        } else if (a[i] <= prefix) {
            valid = false;
        }
        prefix += a[i];
    }

    cout << (valid ? "YES" : "NO") << '\n';
    if (valid) {
        for (ll &i : a) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
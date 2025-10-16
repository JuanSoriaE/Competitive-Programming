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

#define MAX_N 200000
int a[MAX_N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll fa = 0;
    for (int i = 0; i < n; i++)
    if (i & 1) fa -= a[i];
    else fa += a[i];

    ll ans = max(fa, fa + n - 1 - (n % 2 == 0));
    ll max_even = LLONG_MIN / 2, max_odd = LLONG_MIN / 2;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            ans = max(ans, fa + i + 2 * a[i] + max_even);
            max_odd = max(max_odd, 2LL * a[i] - i);
        } else {
            ans = max(ans, fa + i - 2 * a[i] + max_odd);
            max_even = max(max_even, -2LL * a[i] - i);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
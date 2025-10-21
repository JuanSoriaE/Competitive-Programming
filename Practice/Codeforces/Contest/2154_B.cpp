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
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (i & 1) a[i] = mx;
    }

    ll ans = (a[0] >= a[1] ? a[0] - a[1] + 1 : 0) + (n & 1 && a[n - 1] >= a[n - 2] ? a[n - 1] - a[n - 2] + 1 : 0);
    for (int i = 2; i < n - 1; i += 2)
    if (!(a[i] < a[i - 1] && a[i] < a[i + 1]))
        ans += a[i] - a[i - 1] + 1;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
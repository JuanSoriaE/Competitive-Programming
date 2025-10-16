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

#define MAX_N 100000
int a[MAX_N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    ll mult = m, ans = 0;
    for (int i = n - 1, cnt = 0; cnt < min(n, m); i--, cnt++, mult--)
        ans += mult * a[i];

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
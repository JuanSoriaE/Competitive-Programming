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

int a[MAX_N], b[MAX_N];

void solve() {
    int n, k; cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    for (int i = 0; i < k; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + k);

    int j = n - 1;
    for (int i = 0; i < k; i++) {
        j = j - b[i] + 1;
        if (j < 0) break;
        ans -= a[j];
        j--;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
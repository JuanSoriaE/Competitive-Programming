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
int cnt[MAX_N + 1], suffix[MAX_N + 2];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++)
        cnt[i] = suffix[i] = 0;
    suffix[n + 1] = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    for (int i = n; i >= 1; i--)
        suffix[i] = suffix[i + 1] + cnt[i];

    int ans = 1;
    for (int g = 2; g <= n; g++) {
        int sum = cnt[g] + (2 * g <= n ? cnt[2 * g] : 0) + (3 * g <= n ? cnt[3 * g] : 0) +
                  (4 * g <= n ? suffix[4 * g] : 0);
        if (sum >= n - k) ans = g;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
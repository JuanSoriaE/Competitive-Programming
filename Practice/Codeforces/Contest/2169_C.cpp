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

void solve() {
    int n, a; cin >> n;

    ll prefix = 0, max_profit = 0, mini = 0;
    for (int r = 1; r <= n; r++) {
        cin >> a;
        prefix += a;
        ll f_r = r * static_cast<ll>(r + 1) - prefix;
        max_profit = max(max_profit, f_r - mini);
        mini = min(mini, f_r);
    }

    cout << max_profit + prefix << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
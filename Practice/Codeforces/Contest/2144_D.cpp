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
#define MAX_C 200000

int c[MAX_N], tags_cnt[MAX_C + 1], prefix_cnt[MAX_C + 1];

void solve() {
    for (int i = 0; i <= MAX_C; i++) {
        tags_cnt[i] = 0;
        prefix_cnt[i] = 0;
    }

    int n; ll y; cin >> n >> y;
    int max_c = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        max_c = max(max_c, c[i]);
        tags_cnt[c[i]]++;
    }
    if (max_c == 1) {
        cout << n << "\n";
        return;
    }

    for (int i = 1; i <= max_c; i++)
        prefix_cnt[i] = prefix_cnt[i - 1] + tags_cnt[i];

    ll ans = LLONG_MIN;
    for (ll x = 2; x <= max_c; x++) {
        ll income = 0;
        for (ll price = 1; price <= ceil(max_c, x); price++) {
            int l = (price - 1) * x + 1, r = min(static_cast<ll>(max_c), price * x);

            int in_range = prefix_cnt[r] - prefix_cnt[l - 1];
            int need = in_range - min(in_range, tags_cnt[price]);

            income += in_range * price - need * y;
        }
        ans = max(ans, income);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
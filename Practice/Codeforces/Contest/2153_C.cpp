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
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    ll p = 0;
    vector<int> odd;
    int sides = 0;
    for (auto &[a, count] : cnt) {
        if (count & 1) odd.push_back(a);
        p += (ll)a * (count - count % 2);
        sides += (count - count % 2);
    }

    ll ans = (sides > 2 ? p : 0);
    for (int i = 1; i < sz(odd); i++)
    if (odd[i - 1] + p > odd[i])
        ans = max(ans, p + odd[i - 1] + odd[i]);

    for (int i = 0; i < sz(odd); i++)
    if (p > odd[i])
        ans = max(ans, p + odd[i]);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
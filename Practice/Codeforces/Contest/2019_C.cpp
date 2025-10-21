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

int solve() {
    int n; ll k; cin >> n >> k;
    ll mx = 0, total = 0;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        mx = max(mx, a);
        total += a;
    }

    for (int i = n; i > 1; i--) {
        ll min_req = mx * i;
        if (total < min_req) {
            if (min_req - total <= k) return i;
        } else if ((i - (total % i)) % i <= k) return i;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}
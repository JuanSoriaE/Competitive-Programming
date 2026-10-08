#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;

int a[MAX_N];
ll ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n  >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll cur = 0, maxi = LLONG_MIN;
    for (int i = n - 1; i >= 0; i--) {
        cur += a[i];
        maxi = max(maxi, cur);
        ans[i] = maxi;
        if (cur < 0) cur = 0;
    }

    while (q--) {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }

    return 0;
}
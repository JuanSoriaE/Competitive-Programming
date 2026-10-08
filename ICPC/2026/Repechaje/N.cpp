#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll l, r; cin >> l >> r;
    ll sum = 1, cur = 2;

    ll ans = 0;
    while (sum <= r) {
        if (sum >= l && sum <= r) ans++;

        sum += cur;
        cur++;
    }
    cout << ans << '\n';

    return 0;
}
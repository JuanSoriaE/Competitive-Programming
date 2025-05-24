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
#define rep(i, s, n) for (int = s; i < n; i++)

ll a, b, c;

ll f(ll x) {
    return abs((a + c)*(x * x * x) - b * (x * x) + b * c * x + (x + c) * (x - a));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> a >> b >> c;
    int q, x; cin >> q;
    ll ans = 0;
    while (q--) {
        cin >> x;
        ans ^= f(x);
    }
    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

ll fact(ll n) {
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll n; cin >> n;
    ll ans = fact(n) / (2LL * fact(n - 2));
    cout << ans << '\n';
    return 0;
}
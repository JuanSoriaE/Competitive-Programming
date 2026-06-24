#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

ll digits_xor(ll n, ll b) {
    ll res = 0;
    while (n) {
        res ^= n % b;
        n /= b;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll x; cin >> x;
    ll fsqrt = sqrtl(x);
    
    set<ll> ans;
    for (ll b = 2; b <= fsqrt; b++) {
        if (digits_xor(x, b) == 0)
        ans.insert(b);
    }

    for (ll a = 1; (__int128)a * a <= x; a++) {
        if (x % a == 0) {
            ll b = x / a - 1;
            if (b > fsqrt && b > 1)
                ans.insert(b);
            if (x / a != a) {
                ll c = a - 1;
                if (b > fsqrt && c > 1)
                    ans.insert(c);
            }
        }
    }

    cout << sz(ans) << '\n';

    return 0;
}
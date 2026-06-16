#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

ll get_palindromes(ll x) {
    if (x < 200) {
        int ans = 0;
        for (int i = 1; i <= x; i++) {
            string s = to_string(i);
            string s_rev = s; reverse(all(s_rev));
            if (s == s_rev) ans++;
        }
        return ans;
    }

    string s = to_string(x);
    string s_rev = s; reverse(all(s_rev));
    const int n = sz(s);

    ll res = (s == s_rev ? 1 : 0);
    int mult = pow(10LL, (n - 1) / 2);
    for (int i = 0; i < n / 2; i++) {
        ll add = (s[i] - '0' - (i == 0 ? 1 : 0)) * mult;
        res += add;
        mult /= 10;
    }

    // for (int i = 1; i < n; i++)
    //     res += 9 * pow(10LL, (i - 1) / 2);

    return res;
}

ll brute(int x) {
    ll ans = 0;
    for (int i = 1; i <= x; i++) {
        string s = to_string(i);
        string s_rev = s; reverse(all(s_rev));
        if (s == s_rev && sz(s) == sz(to_string(x))) ans++;;
    }
    return ans;
}

void solve() {
    for (ll x = 1000; x <= 999999999; x++) {
        ll a = get_palindromes(x), b = brute(x);
        if (a != b) {
            debug(x)
            debug(a)
            debug(b)
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    // int q; cin >> q;
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

ll get_count(ll x) {
    if (x < 10) return x;

    string s = to_string(x);
    const int n = sz(s);

    int half = ceil(n, 2);
    string prefix_s = s.substr(0, half);
    ll prefix = stoll(prefix_s);
    ll res = (prefix - pow(10LL, half - 1));

    string t = prefix_s;
    if (n & 1) t.pop_back();
    reverse(all(t));
    ll palindrome_num = stoll(prefix_s + t);

    if (palindrome_num <= x)
        res++;

    for (int i = 1; i < n; i++)
        res += 9 * pow(10LL, (i - 1) / 2);

    return res;
}

void solve() {
    ll l, r; cin >> l >> r;
    cout << (get_count(r) - get_count(l - 1)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> q;
    while (q--) solve();
    return 0;
}
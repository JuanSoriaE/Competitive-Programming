#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

struct Fraction {
    ll a, b;
    Fraction(ll a, ll b) : a(a), b(b) {}
    void reduce() {
        ll gcd = __gcd(a, b);
        a /= gcd; b/= gcd;
        if (b < 0) a = -a, b = -b;
    }
    Fraction operator+(const Fraction &o) const {
        return Fraction((a * o.b) + (o.a * b), b * o.b);
    }
    Fraction operator-(const Fraction &o) const {
        return Fraction((a * o.b) - (o.a * b), b * o.b);
    }
    bool operator<(const Fraction &o) const {
        ll x = (ll)a * o.b;
        ll y = (ll)o.a * b;
        if (x == y) return false;
        return max(x, y) == y;
    }
};

Fraction distance(int i, int j, int h_i, int h_j, int h_j_1) {
    Fraction res = Fraction(j - i, 1) - Fraction(h_j - h_i, h_j - h_j_1);
    res.reduce();
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<ll> h(n);
    for (ll &i : h) cin >> i;

    vector<pair<ll, int>> stk;
    Fraction ans(0, 1);
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.back().first < h[i]) {
            ans = max(ans, distance(
                stk.back().second, i,
                stk.back().first, h[i],
                h[i - 1]
            ));
            stk.pop_back();
        }

        if (!stk.empty()) {
            ans = max(ans, distance(
                stk.back().second, i,
                h[i], stk.back().first,
                h[stk.back().second + 1]
            ));
        }
        stk.push_back({h[i], i});
    }
    if (ans.b > 1)
        cout << ans.a << '/' << ans.b << '\n';
    else
        cout << ans.a << '\n';

    return 0;
}
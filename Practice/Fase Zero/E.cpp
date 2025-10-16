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

vector<ll> divisors(ll n) {
    vector<ll> div(2 * sqrt(n) + 1, -1);
    int l = 0, r = sz(div) - 1;
    for (ll i = 1; i * i <= n; i++)
    if (n % i == 0) {
        div[l++] = i;
        if (n / i != i)
        div[r--] = n / i;
    }
    return div;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll y, k; cin >> y >> k;
    vector<ll> div = divisors(y);
    ll prev = 1;
    for (ll &d : div) {
        if (d == -1 || d % prev) continue;

        ll steps = (d - prev) / prev;
        if (k < steps) break;

        k -= steps;
        prev = d;
    }
    cout << prev * (k + 1) << "\n";

    return 0;
}
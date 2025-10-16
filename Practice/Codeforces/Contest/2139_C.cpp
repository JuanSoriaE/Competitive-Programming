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

int ans[120];

void solve() {
    int k; ll x; cin >> k >> x;
    ll total = 1LL << (k + 1);
    ll a = x, b = total - a;

    int n = 0;
    while (a != b) {
        if (a < b) {
            ans[n++] = 1;
            a <<= 1;
            b = total - a;
        } else {
            ans[n++] = 2;
            b <<= 1;
            a = total - b;
        }
    }

    cout << n << '\n';
    for (int i = n - 1; i >= 0; i--)
    cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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

int log2_floor(ll x) {
    return 63 - __builtin_clzll(x);
}

int log2_ceil(ll x) {
    int floor = log2_floor(x);
    return floor + !((1 << floor) == x);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll bits; cin >> bits;
    ll a = bits * 8 * 1000000;
    int ans = log2_ceil(a);
    cout << ans << "\n";

    return 0;
}
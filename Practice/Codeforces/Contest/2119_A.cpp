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

int solve() {
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a > b)
        return ((a & 1) && a == b + 1 ? y : -1);

    int evens = b / 2 - a / 2;
    int odds = b - a - evens;

    return odds * min(x, y) + evens * x;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
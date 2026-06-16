#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ull unsigned long long
#define ld long double

bool solve() {
    ll x1, y1, r1, x2, y2, r2, k;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 >> k;

    ull d_2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    return k <= 2 * r1 || k <= 2 * r2 || (
        d_2 <= (r1 + r2) * (r1 + r2) &&
        k <= sqrt(d_2) + r1 + r2
    );
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

void solve() {
    int n, x, y, z; cin >> n >> x >> y >> z;
    int op1 = ceil(n, (x + y));
    int op2 = n > z * x ? z + ceil((n - z * x), (x + 10 * y)) : INT_MAX;

    cout << min(op1, op2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

void solve() {
    ll n; cin >> n;
    if (n == 10) {
        cout << "-1\n";
        return;
    }

    if (n % 12 == 10)
        cout << "22 " << (n - 22) << '\n';
    else
        cout << (n % 12) << " " << (n - (n % 12)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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
    int n, m = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > 1) m++;
    }

    if (!m)
        cout << (n % 3 == 1 ? "Sprague" : "Grundy") << '\n';
    else if (m == 1)
        cout << (n % 3 != 2 ? "Sprague" : "Grundy") << '\n';
    else
        cout << "Grundy\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
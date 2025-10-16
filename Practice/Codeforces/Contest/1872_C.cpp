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

int divisor(int n) {
    int div = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div = i;
        }
    }
    return div;
}

void solve() {
    int l, r; cin >> l >> r;
    if (r < 4) {
        cout << -1 << '\n'; return;
    }

    if (l != r) {
        cout << (r - r % 2) / 2 << ' ' << (r - r % 2) / 2;
    } else {
        int div = divisor(l);
        if (div == 1) cout << -1;
        else cout << div << ' ' << (l - div);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
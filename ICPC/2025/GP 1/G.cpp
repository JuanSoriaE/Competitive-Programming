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

void solve_odd(int &n, int &a) {
    for (int i = 0; i < n / 2; i++)
        cout << (i % 2 ? -1 : 0) << " " << i << "\n";

    int need = 2 * (a + 1) - n;
    cout << 0 << " " << (n / 2 + need) << "\n";

    int x = (n / 2) % 2,
        y = n / 2 - 1;
    for (int i = 0; i < n / 2; i++) {
        cout << x << " " << y << "\n";

        x = (x + 1) % 2;
        y--;
    }
}

void solve_even(int &n, int &a) {
    for (int i = 0; i < n / 2 - ((n / 2) % 2 == 0); i++)
        cout << (i % 2 ? -1 : 0) << " " << i << "\n";

    int need = 2 * (a + 1) - n;
    if ((n / 2) % 2) {
        cout << need + 1 << " " << (n / 2 - 1) << "\n";
    } else {
        cout << -(need + 1) << " " << (n / 2 - 1) << "\n";
    }

    int x = 0,
        y = n / 2 - 1 - (n / 2) % 2;
    for (int i = 0; i < n / 2 - ((n / 2) % 2); i++) {
        cout << x << " " << y << "\n";

        x = (x + 1) % 2;
        y--;
    }
}

void solve() {
    int n, a; cin >> n >> a;
    if (a < n / 2.0f - 1) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    if (n % 2) solve_odd(n, a);
    else solve_even(n, a);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
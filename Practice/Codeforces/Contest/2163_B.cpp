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

void solve() {
    int n; cin >> n;
    int pos_1, pos_n;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p == 1) pos_1 = i;
        else if (p == n) pos_n = i;
    }

    string x; cin >> x;
    if (x[0] == '1' || x[n - 1] == '1' || x[pos_1] == '1' || x[pos_n] == '1') {
        cout << "-1\n";
        return;
    }

    cout << "5\n";
    cout << "1 " << (pos_1 + 1) << '\n';
    cout << "1 " << (pos_n + 1) << '\n';

    cout << (pos_n + 1) << ' ' << n << '\n';
    cout << (pos_1 + 1) << ' ' << n << '\n';

    cout << (min(pos_1, pos_n) + 1) << ' ' << (max(pos_1, pos_n) + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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
    int n; cin >> n;
    vector<int> b(n);
    for (int &i : b) cin >> i;

    bool valid = b[0] == 1;
    for (int i = 1; i < n; i++) {
        if (b[i] < b[i - 1] || (b[i] - b[i - 1]) > 1)
            valid = false;
    }

    if (valid) {
        cout << "YES\n";
        for (int &i : b) cout << i << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
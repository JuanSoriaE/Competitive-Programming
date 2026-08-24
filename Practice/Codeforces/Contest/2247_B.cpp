#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    if (m < k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << m - (k - 1) << ' ';
    for (int i = 0; i < n - 1; i++)
        cout << 1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
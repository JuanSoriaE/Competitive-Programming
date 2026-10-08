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

int c[MAX_N], k[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        total += c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        if (k[i] > c[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, total - c[i] + k[i]);
    cout << ans << '\n';

    return 0;
}
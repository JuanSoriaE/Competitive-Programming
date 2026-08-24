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

int a[MAX_N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt1 = 0, cnt2 = 0, cnt2_min = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        cnt1 += a[i] == 1 ? 1 : -1;
        cnt2 += a[i] == 3 ? -1 : 1;

        if (cnt2 - cnt2_min >= 0) {
            cout << "YES\n";
            return;
        }

        if (cnt1 >= 0)
            cnt2_min = min(cnt2_min, cnt2);
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
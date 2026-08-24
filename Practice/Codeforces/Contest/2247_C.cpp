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
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int zeros_bad = 0, ones_bad = 0,
        zeros_good = 0, ones_good = 0;
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        if (b) {
            if (a[i]) ones_good++;
            else zeros_bad++;
        } else {
            if (!a[i]) zeros_good++;
            else ones_bad++;
        }
    }

    int ans;
    if (!zeros_bad && !ones_bad) ans = 0;
    else if (!ones_bad) {
        if (ones_good && zeros_good) ans = 2;
        else ans = -1;
    } else if (ones_bad & 1) ans = 1;
    else ans = 2;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
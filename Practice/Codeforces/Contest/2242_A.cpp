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
    int k; cin >> k;

    int cnt_3 = 0, cnt_2 = 0;
    for (int i = 0; i < k; i++) {
        int c; cin >> c;
        if (c >= 3) cnt_3++;
        else if (c == 2) cnt_2++;
    }

    cout << (cnt_3 || cnt_2 > 1 ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
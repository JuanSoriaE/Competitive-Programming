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

int diff[MAX_N], closed[MAX_N];

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    for (int i = 0; i < n; i++)
        diff[i] = (s[i] - '0') == (i % 2) ? 0 : 1;

    for (int i = 1; i < n; i++)
        closed[i] = closed[i - 1] + (diff[i - 1] != diff[i]);

    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        l--, r--;
        int blocks = closed[r] - closed[l] + 1;
        cout << (blocks / 2 <= k ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
// https://codeforces.com/contest/1872/problem/E
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

#define MAX_N 100000

int a[MAX_N], prefix_xor[MAX_N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    string s; cin >> s;
    int all = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        prefix_xor[i] = (i == 0 ? 0 : prefix_xor[i - 1]) ^ a[i];
        all ^= a[i];
        if (s[i] == '1') ones ^= a[i];
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            --l; --r;
            int win = prefix_xor[r] ^ (l == 0 ? 0 : prefix_xor[l - 1]);
            ones ^= win;
        } else {
            int g; cin >> g;
            cout << (g ? ones : all ^ ones) << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
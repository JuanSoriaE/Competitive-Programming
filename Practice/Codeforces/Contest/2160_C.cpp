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
    int l = 31, r = -1;
    for (int i = 0; i < 30; i++) {
        if (n & (1 << i)) {
            l = min(l, i);
            r = i;
        }
    }

    int size = r + l + 1;
    if (size & 1 && n & (1 << (size / 2))) {
        cout << "NO\n";
        return;
    }

    while (l < r) {
        if (((n >> l) & 1) != ((n >> r) & 1)) {
            cout << "NO\n";
            return;
        }
        l++, r--;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
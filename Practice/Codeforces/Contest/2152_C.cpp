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

#define MAX_N 250000
int a[MAX_N], prefix_cnt[MAX_N], prefix_diff[MAX_N];

void solve() {
    int n, q; cin >> n >> q;
    cin >> a[0];
    prefix_cnt[0] = a[0] == 0;
    prefix_diff[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        prefix_cnt[i] = prefix_cnt[i - 1] + (a[i] == 0);
        prefix_diff[i] = prefix_diff[i - 1] + (a[i] != a[i - 1]);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        int cnt = prefix_cnt[r] - (l > 0 ? prefix_cnt[l - 1] : 0);
        if ((r - l + 1) % 3 || cnt % 3) {
            cout << "-1\n"; continue;
        }

        int diff = prefix_diff[r] - prefix_diff[l];
        cout << ((r - l + 1) / 3 + (diff == (r - l))) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
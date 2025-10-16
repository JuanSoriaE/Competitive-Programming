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

#define MAX_N 200000
ll a[2 * MAX_N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];

    ll mid = 0, edge_sum = 0;
    for (int i = 0; i < 2 * n; i += 2)
        mid += a[i + 1] - a[i];

    for (int i = 0; i < n; i++) {
        cout << mid + edge_sum << ' ';
        ll edge = a[2 * n - 1 - i] - a[i];
        mid = -mid + edge;
        edge_sum += edge;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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

int ans[2 * MAX_N];

void solve() {
    int n; cin >> n;
    ans[0] = ans[n] = n;
    for (int x = n - 1, i = 1; x > 0; x--, i++)
        ans[i] = ans[i + 2 * x] = x;
    for (int i = 0; i < 2 * n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
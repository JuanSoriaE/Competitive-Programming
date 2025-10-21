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

int ans[32];

int getMSB(int n) {
    if (n == 0) return -1;
    return 31 - __builtin_clz(n);
}

void solve() {
    int a, b; cin >> a >> b;
    if (getMSB(b) > getMSB(a)) {
        cout << -1 << '\n';
        return;
    }

    int n = 0;
    for (int i = 0; i < 32; i++)
    if ((a & (1 << i)) != (b & (1 << i)))
        ans[n++] = (1 << i);

    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    if (n) cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
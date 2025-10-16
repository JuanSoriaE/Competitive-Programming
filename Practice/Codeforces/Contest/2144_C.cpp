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

#define MAX_N 100
#define MOD 998244353

int a[MAX_N], b[MAX_N];

ll solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll ans = 2;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1] && b[i] < b[i - 1] && a[i] < b[i - 1] && b[i] < a[i - 1])
            return 0;
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1] && a[i] >= b[i - 1] && b[i] >= a[i - 1])
            ans = (ans * 2LL) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
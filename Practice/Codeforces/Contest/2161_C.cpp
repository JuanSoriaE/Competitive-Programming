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
int a[MAX_N], ans[MAX_N];

void solve() {
    int n, X; cin >> n >> X;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int l = 0, r = n - 1, ans_i = 0;
    ll sum = 0, earned = 0;
    while (l <= r) {
        if (sum / X != (sum + a[r]) / X)
            sum += a[r], earned += a[r], ans[ans_i++] = a[r--];
        else
            sum += a[l], ans[ans_i++] = a[l++];
    }

    cout << earned << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
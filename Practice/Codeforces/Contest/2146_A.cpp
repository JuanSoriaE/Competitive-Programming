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

int cnt[MAX_N + 1];

void solve() {
    for (int i = 1; i <= MAX_N; i++) cnt[i] = 0;

    int n; cin >> n;
    int different = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!cnt[a]) different++;
        cnt[a]++;
    }

    sort(cnt, cnt + n + 1, [](const int &a, const int &b) {
        return a < b;
    });

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) continue;
        ans = max(ans, cnt[i] * different--);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
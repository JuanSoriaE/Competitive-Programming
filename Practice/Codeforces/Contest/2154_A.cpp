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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int last_one = -1, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;

        if (last_one == -1 || last_one < i - k + 1)
            ans++;
        last_one = i;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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
    string s; cin >> s;
    int a = count(all(s), 'a');
    int b = count(all(s), 'b');

    int cur_a = 0, cur_b = 0;
    map<int, int> dp; dp[0] = -1;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') cur_a++;
        else cur_b++;

        dp[cur_a - cur_b] = i;
        int c = -a + cur_a + b - cur_b;
        if (dp.count(c)) ans = min(ans, i - dp[c]);
    }
    cout << (ans == n ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
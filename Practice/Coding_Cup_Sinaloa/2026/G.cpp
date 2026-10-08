#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> segs(n);
    for (auto &[s, e] : segs) cin >> s >> e;

    sort(all(segs));

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        int max_prev = 0;
        for (int j = 0; j < i; j++)
        if (segs[j].second <= segs[i].first)
            max_prev = max(max_prev, dp[j]);

        dp[i] = max_prev + 1;
    }

    cout << *max_element(all(dp)) << '\n';

    return 0;
}
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
    int n, m, k; cin >> n >> m >> k;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        mp[c].push_back(i);
    }

    int ans = 0;
    for (auto &[c, v] : mp) {
        int l = 0, res = 1, deleted = 0;
        for (int r = 1; r < sz(v); r++) {
            deleted += v[r] - v[r - 1] - 1;
            while (deleted > k && l + 1 < sz(v)) {
                deleted -= v[l + 1] - v[l] - 1;
                l++;
            }
            if (deleted <= k)
                res = max(res, r - l + 1);
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';

    return 0;
}
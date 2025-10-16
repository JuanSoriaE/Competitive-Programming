// https://codeforces.com/gym/102966/problem/B
// https://atcoder.jp/contests/arc173/tasks/arc173_b
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> v(n); for (auto &a : v) cin >> a.first >> a.second;

    int T = 15;
    int mx = 1;
    while (T--) {
        int idx = random(0, n - 1);
        map<pair<int, int>, int> mp;

        for (int i = 0; i < n; i++) {
            if (i == idx) continue;

            int dx = abs(v[i].first - v[idx].first),
                dy = abs(v[i].second - v[idx].second);

            int g = gcd(dx, dy);
            dx /= g; dy /= g;

            mp[{dx, dy}]++;
            mx = max(mx, mp[{dx, dy}] + 1);
        }
    }

    cout << (mx > 2 * n / 3 ? n - mx : n / 3) << "\n";
    return 0;
}
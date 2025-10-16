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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    int mx = 1;
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, int> mp;
        for (int j = i + 1; j < n; j++) {
            int dx = abs(v[i].first - v[j].first),
                dy = abs(v[i].second - v[j].second);

            int g = gcd(dx, dy);
            dx /= g; dy /= g;
            mp[{dx, dy}]++;
            
            mx = max(mx, mp[{dx, dy}] + 1);
        }
    }

    cout << (mx / 2 <= n - mx ? n / 3 : n - mx) << "\n";
    return 0;
}
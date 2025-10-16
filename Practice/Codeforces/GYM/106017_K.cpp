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
    for (auto &i : v) cin >> i.first;
    for (auto &i : v) cin >> i.second;

    ll ans = 0;
    int mx = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i - 1].second == v[i].second)
            mx = max(v[i].first, mx);
        else {
            ans += mx;
            mx = v[i].first;
        }
    }
    ans += mx;

    cout << ans << "\n";

    return 0;
}
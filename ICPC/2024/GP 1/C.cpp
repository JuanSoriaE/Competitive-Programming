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
    int L, W, H; cin >> L >> W >> H;
    int l, w, h; cin >> l >> w >> h;
    vector<int> v = {l, w, h};
    sort(all(v));

    int ans = 0;
    do {
        ans = max(ans, (L / v[0]) * (W / v[1]) * (H / v[2]));
    } while (next_permutation(all(v)));

    cout << ans << "\n";
    return 0;
}
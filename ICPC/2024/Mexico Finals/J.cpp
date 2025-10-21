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
    int t, n; cin >> t >> n;
    ld theta = t * (PI / static_cast<ld>(180));

    vector<pair<int, ld>> inter(n);
    for (int i = 0; i < n; i++) {
        cin >> inter[i].first;
        int h; cin >> h;
        inter[i].second = inter[i].first + static_cast<ld>(h) / tan(theta);
    }

    sort(all(inter));

    int l = inter[0].first;
    ld r = inter[0].second;

    ld ans = 0;
    for (int i = 1; i < n; i++) {
        if (inter[i].first <= r) {
            r = max(r, inter[i].second);
            continue;
        }

        ans += r - l;
        l = inter[i].first, r = inter[i].second;
    }
    ans += r - l;

    cout << setprecision(250) << ans << '\n';
    return 0;
}
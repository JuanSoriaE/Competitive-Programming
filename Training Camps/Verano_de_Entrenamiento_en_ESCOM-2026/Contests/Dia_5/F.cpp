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
    // r, l
    set<pair<int, int>> segs;
    while (n--) {
        int l, r; cin >> l >> r;
        auto it = segs.lower_bound({l, 0});

        while (it != segs.end() && (*it).second <= r) {
            l = min(l, (*it).second);
            r = max(r, (*it).first);
            it = segs.erase(it);
        }

        segs.insert({r, l});
        cout << sz(segs) << ' ';
    }
    cout << '\n';

    return 0;
}
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
    int n, k; cin >> n >> k;

    vector<int> starts, ends;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (b - a + 1 >= k) {
            ans++; continue;
        }

        int l = a % k, r = b % k;
        if (r < l) {
            starts.push_back(0);
            starts.push_back(l);

            ends.push_back(r);
            ends.push_back(k - 1);
        } else {
            starts.push_back(l);
            ends.push_back(r);
        }
    }

    sort(all(starts));
    sort(all(ends));

    int s = 0, e = 0, cur = 0, maxi = 0;
    while (s < sz(starts)) {
        if (starts[s] <= ends[e])
            cur++, s++;
        else
            cur--, e++;
        maxi = max(maxi, cur);
    }

    cout << ans + maxi << '\n';

    return 0;
}
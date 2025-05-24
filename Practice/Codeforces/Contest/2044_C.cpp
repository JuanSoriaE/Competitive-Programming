#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, m, a, b, c; cin >> t;
    while (t--) {
        cin >> m >> a >> b >> c;
        int res = min(m, a) + min(m, b),
            rem = 2 * m - res;
        res += min(rem, c);

        cout << res << "\n";
    }
    return 0;
}
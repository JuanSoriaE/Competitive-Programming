#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    long long cur = 1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++)
            cout << ((cur++ - (
                        (m % k == 0 && r % 2) ? 0 : 1
                    )) % k + 1) << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
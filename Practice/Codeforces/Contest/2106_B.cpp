#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    for (int i = 0, cur = 0; i < n - 1; i++, cur++) {
        if (cur == x) cur++;
        cout << cur << " ";
    }

    cout << (x == n ? n - 1 : x) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
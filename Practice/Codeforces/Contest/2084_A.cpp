#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (!(n % 2)) {
        cout << -1 << "\n";
        return;
    }

    cout << n << " ";
    for (int i = 1; i < n; i++)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
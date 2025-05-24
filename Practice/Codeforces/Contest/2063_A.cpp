#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;

        cout << (l + r == 2 ? 1 : r - l) << "\n";
    }
    return 0;
}
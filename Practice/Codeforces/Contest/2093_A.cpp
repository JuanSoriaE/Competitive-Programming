#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t, k; cin >> t;
    while (t--) {
        cin >> k;
        cout << (k % 2 ? "YES" : "NO") << "\n";
    }

    return 0;
}
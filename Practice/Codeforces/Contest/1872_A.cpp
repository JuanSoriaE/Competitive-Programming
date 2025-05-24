#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    cout << ceil((double)abs(a - b) / (c * 2)) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
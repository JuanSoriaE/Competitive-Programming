#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l, r; cin >> n >> m >> l >> r;
    int l_p = max(l, -m);
    m += l_p;
    int r_p = min(r, m);
    
    cout << l_p << " " << r_p << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
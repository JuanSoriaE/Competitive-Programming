#include <bits/stdc++.h>
using namespace std;

string solve() {
    int a, b, c; cin >> a >> b >> c;
    if (b > a && b > c) return "MOUNTAIN";
    else return "VALLEY";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
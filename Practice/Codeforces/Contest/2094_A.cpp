#include <bits/stdc++.h>
using namespace std;

string solve() {
    string s, ans;
    int i = 3;
    while (i--) {
        cin >> s;
        ans += s[0];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
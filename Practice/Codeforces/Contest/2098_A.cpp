#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int cnt[10] = {0};
    for (char &c : s)
        cnt[c - '0']++;

    for (int i = 9; i >= 0; i--)
    for (int d = i; d < 10; d++)
    if (cnt[d]) {
        cout << d;
        cnt[d]--;
        break;
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
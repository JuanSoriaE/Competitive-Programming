#include <bits/stdc++.h>
using namespace std;

int solve() {
    string n; cin >> n;
    int ans = 0;
    int i = n.size() - 1;
    while (n[i] == '0') i--, ans++;

    int last_non_zero = n.size() - 1 - ans;
    for (int j = 0; j < last_non_zero; j++)
    if (n[j] != '0') ans++;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
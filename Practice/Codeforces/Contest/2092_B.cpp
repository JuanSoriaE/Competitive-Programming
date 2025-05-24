#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    
    int cnt_a[2] = {0}, cnt_b[2] = {0};
    for (int i = 0; i < n; i++) {
        cnt_a[i % 2] += (a[i] == '1');
        cnt_b[i % 2] += (b[i] == '0');
    }

    return cnt_b[1] >= cnt_a[0] && cnt_b[0] >= cnt_a[1];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}
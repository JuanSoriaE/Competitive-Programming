#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> b(n), c(m);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int res = 0, i = n - 1;
    for (int j = 0; j < m; j++) {
        while (i >= 0 && b[i] + c[j] > k) i--;

        res += i + 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t, n, m, k, aux, cnt; cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}
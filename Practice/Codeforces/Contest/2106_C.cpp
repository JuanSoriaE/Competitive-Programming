#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    bool all_unknow = true;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        all_unknow &= (b[i] == -1);
    }

    if (!all_unknow) {
        int sum = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1 && sum != -1 && a[i] + b[i] != sum)
                return 0;
            if (b[i] != -1)
                sum = a[i] + b[i];
        }

        for (int i = 0; i < n; i++)
        if (sum - a[i] < 0 || sum - a[i] > k)
            return 0;
        return 1;
    }

    return mn + k - mx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
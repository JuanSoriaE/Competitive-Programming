#include <bits/stdc++.h>

using namespace std;

long long sum(long long l, long long r) {
    return r * (r + 1) / 2 - l * (l - 1) / 2;
}

long long solve() {
    int n, k; cin >> n >> k;
    int l = 0, r = n - 1;
    long long res = LONG_LONG_MAX;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        long long val = sum(k, k + mid) - sum(k + mid + 1, k + n - 1);

        if (val == 0) return 0;

        if (val < 0) l = mid + 1;
        else r = mid - 1;

        res = min(res, abs(val));
    }

    return res;
}

int main() {
    int t; cin >> t;

    while (t--)
        cout << solve() << "\n";

    return 0;
}
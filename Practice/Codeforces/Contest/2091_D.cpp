#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

void solve() {
    ll n, m, k; cin >> n >> m >> k;

    int l = 1, r = m, mid;
    ll poss_benches;
    while (l <= r) {
        mid = l + (r - l) / 2;

        poss_benches = n * (m / (mid + 1) * mid + m % (mid + 1));
        if (poss_benches >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;

    while (t--) solve();
    
    return 0;
}
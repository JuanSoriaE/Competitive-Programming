#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve() {
    int n; cin >> n;
    vector<ll> v(n);
    int cnt[30] = {0};

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < 30; j++)
        if (v[i] & (1 << j))
            cnt[j]++;
    }

    ll ans = 0;
    for (int j = 0; j < n; j++) {
        ll k = v[j], sum = 0;

        for (int i = 0; i < 30; i++)
            if (k & (1 << i)) sum += (1 << i) * (ll)(n - cnt[i]);
            else sum += (1 << i) * (ll)(cnt[i]);

        ans = max(ans, sum);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
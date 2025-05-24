#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool is_possible(vector<ll> &v, int n, ll x, ll k) {
    ll min_officers = 0;

    for (int i = 0; i < n; i++)
        min_officers += (v[i] + x - 1) / x;

    return min_officers <= k;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    ll l = 1, r = 1000000000000000000;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (is_possible(v, n, m, k)) r = m - 1;
        else l = m + 1;
    }

    cout << l << "\n";

    return 0;
}
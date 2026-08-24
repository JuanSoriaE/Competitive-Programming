#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_M = 1000;

pair<ll, ll> moss[MAX_M];
ll n;
int m;

bool is_valid_row(const ll &t, const ll &y) {
    if (y < 0 || y >= n) return true;

    ll l = -1, r = -1;
    for (int i = 0; i < m; i++) {
        if ((moss[i].second > y && moss[i].second - t > y) ||
            (moss[i].second < y && moss[i].second + t < y)) continue;

        if (l == -1)
            l = max(0LL, moss[i].first - t), r = moss[i].first + t;
        else if (moss[i].first - t <= r + 1)
            r = moss[i].first + t;
    }
    return l == 0 && r >= n - 1;
}

bool is_valid(const ll &t) {
    if (!is_valid_row(t, 0) || !is_valid_row(t, n - 1))
        return false;
    for (int i = 0; i < m; i++)
        if (!is_valid_row(t, moss[i].second + t + 1) ||
            !is_valid_row(t, moss[i].second - t - 1))
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        x--, y--;
        moss[i] = {x, y};
    }

    sort(moss, moss + m);

    ll l = 0, r = 1e18;
    ll ans;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (is_valid(m))
            ans = m, r = m - 1;
        else
            l = m + 1;
    }

    cout << ans << '\n';

    return 0;
}
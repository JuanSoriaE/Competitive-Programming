#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int log2_floor(ll x) {
    return 63 - __builtin_clzll(x);
}
int log2_ceiling(ll x) {
    int floor = log2_floor(x);
    return floor + !((1LL << floor) == x);
}

int dfs(ll x, ll y, ll size_) {
    if (x < 2 && y < 2)
        return 0;

    int rotations = 0;
    ll new_x = x, new_y = y;
    ll X = x / size_, Y = y / size_;
    if ((X == 1 && Y == 1) || (X == 1LL && Y == 2LL) || (X == 2 && Y == 1))
        new_x = x - size_, new_y = y - size_;
    else if ((X == 2 && Y == 2) || (X == 2 && Y == 3) || (X == 3 && Y == 2))
        new_x = x - 2LL * size_, new_y = y - 2LL * size_;
    else if ((X == 3 && Y == 3))
        new_x = x - 3LL * size_, new_y = y - 3LL * size_;
    else if ((X == 0 && Y == 2) || (X == 0 && Y == 3) || (X == 1 && Y == 3))
        new_x = 4LL * size_ - y - 1LL, new_y = x, rotations = 1;
    else if ((X == 2 && Y == 0) || (X == 3 && Y == 0) || (X == 3 && Y == 1))
        new_x = y, new_y = 4LL * size_ - x - 1LL, rotations = 3;

    return (rotations + dfs(new_x, new_y, size_ >> 1)) % 4;
}

void solve() {
    ll x, y; cin >> x >> y;
    int max_power = max(log2_ceiling(x + 1), log2_ceiling(y + 1));
    cout << dfs(x, y, 1LL << (max_power - 2)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
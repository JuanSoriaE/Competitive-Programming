#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100000

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    ll dp_neg = 0, dp_pos = 0;
    while (n--) {
        int a; cin >> a;
        if (a > 0)
            dp_pos = max(dp_pos, dp_neg + a);
        else
            dp_neg = max(dp_neg, dp_pos + a);
    }

    cout << max(dp_pos, dp_neg) << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int get_ones(string &s) {
    int res = 0;
    for (char &c : s) if (c == '1') res++;
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    int size = (1 << k) + 1;

    string s, z; cin >> s >> z;

    int s_ones = get_ones(s);
    ll a_val = (ll)s_ones * (n - s_ones);

    int z_ones = get_ones(z);
    ll b_val = (ll)z_ones * (n - z_ones);

    int s_z_ones = 0;
    for (int i = 0; i < n; i++)
    if (s[i] != z[i]) s_z_ones++;
    ll a_b_val = (ll)s_z_ones * (n - s_z_ones);

    int a, b, a_b; a = b = ceil(size, 3), a_b = size - a - b;

    ll ans = a * a_val + b * b_val + a_b * a_b_val;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
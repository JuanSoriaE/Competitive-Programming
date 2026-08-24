#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

ll nb, ns, nc, pb, ps, pc, r;
ll b = 0, s = 0, c = 0;

bool valid(ll qty) {
    ll extra_b = max(qty * b - nb, 0LL);
    ll extra_s = max(qty * s - ns, 0LL);
    ll extra_c = max(qty * c - nc, 0LL);

    ll extra_r = extra_b * pb + extra_s * ps + extra_c * pc;
    return extra_r <= r;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string st; cin >> st;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    for (char &ch : st)
    if (ch == 'B') b++;
    else if (ch == 'S') s++;
    else c++;

    ll l = 0, r_ = 1e13, ans;
    while (l <= r_) {
        ll m = l + (r_ - l) / 2;
        if (valid(m))
            ans = m, l = m + 1;
        else
            r_ = m - 1;
    }
    cout << ans << '\n';

    return 0;
}
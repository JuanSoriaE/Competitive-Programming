#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100000

int a[2 * MAX_N];
bool mex[MAX_N];
int n;

int single_zero(int zero) {
    fill(mex, mex + n, false);

    int l, r; l = r = zero;
    while (l >= 0 && r < 2 * n && a[l] == a[r]) {
        mex[a[l]] = true;
        l--, r++;
    }

    return find(mex, mex + n, false) - mex;
}

int double_zero(int first_zero, int second_zero) {
    fill(mex, mex + n, false);

    int l = first_zero, r = second_zero;
    while (l <= r && a[l] == a[r]) {
        mex[a[l]] = true;
        l++, r--;
    }
    if (l < r) return 0;

    l = first_zero; r = second_zero;
    while (l >= 0 && r < 2 * n && a[l] == a[r]) {
        mex[a[l]] = true;
        l--, r++;
    }

    return find(mex, mex + n, false) - mex;
}

void solve() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];

    int first_zero = find(a, a + 2 * n, 0) - a,
        second_zero = find(a + first_zero + 1, a + 2 * n, 0) - a;

    int ans = max(single_zero(first_zero), single_zero(second_zero));
    ans = max(ans, double_zero(first_zero, second_zero));

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
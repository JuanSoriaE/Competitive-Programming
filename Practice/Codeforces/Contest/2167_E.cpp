#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

#define MAX_N 200000
int a[MAX_N];

int n, k, x;

bool is_valid(int mid) {
    int can = max(a[0] - mid + 1, 0) + max(x - (a[n - 1] + mid) + 1, 0);
    for (int i = 0; i < n - 1; i++)
        can += max(static_cast<ll>(a[i + 1]) - a[i] - 2LL * mid + 1, 0LL);

    return can >= k;
}

void solve() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int l = 0, r = 1000000000, d;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (is_valid(mid)) {
            d = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    if (d == 0) {
        for (int i = 0; i < k; i++)
        cout << i << ' ';
        cout << '\n';
        return;
    }

    vector<int> ans(k);
    int ans_i = 0;
    int can = max(a[0] - d + 1, 0);
    for (int i = 0, s = 0; i < can && ans_i < k; i++, s++)
        ans[ans_i++] = s;

    for (int i = 0; i < n - 1; i++) {
        can = max(static_cast<ll>(a[i + 1]) - a[i] - 2LL * d + 1, 0LL);
        for (int j = 0, s = a[i] + d; j < can && ans_i < k; j++, s++)
            ans[ans_i++] = s;
    }

    can = max(x - (a[n - 1] + d) + 1, 0);
    for (int i = 0, s = a[n - 1] + d; i < can && ans_i < k; i++, s++)
        ans[ans_i++] = s;

    for (int i = 0; i < k; i++)
    cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
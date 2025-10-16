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

#define MAX_N 100000

int a[MAX_N];
int n, k;

bool is_valid(int mid) {
    int first_occ = INT_MAX, last_occ;
    for (int i = 0; i < n; i++) {
        if (a[i] >= mid) continue;

        first_occ = min(first_occ, i);
        last_occ = i;
    }

    if (first_occ == INT_MAX) return 1;
    if (last_occ - first_occ + 1 > k) return 0;

    for (int i = last_occ, add = k; i >= first_occ; i--, add--)
        if (a[i] + add < mid) return 0;

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 1, r = 1e9 + 1e5;
    int ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (is_valid(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";

    return 0;
}
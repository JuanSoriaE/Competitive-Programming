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
bool vst[MAX_N + 1];
int n;

int solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) vst[i] = 0;
    int first_zero = INT_MAX, last_zero = -1;
    int first_wrong = INT_MAX, last_wrong = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) vst[a[i]] = 1;
        if (a[i] == 0) {
            first_zero = min(first_zero, i);
            last_zero = i;
        } else if (a[i] != i + 1) {
            first_wrong = min(first_wrong, i);
            last_wrong = i;
        }
    }

    int missing = -1;
    for (int i = 1; last_zero != -1 && i <= n && missing == -1; i++)
    if (!vst[i]) missing = i;

    if (last_zero == -1)
        return last_wrong == -1 ? 0 : last_wrong - first_wrong + 1;
    if (first_zero == last_zero && missing == first_zero + 1)
        return last_wrong == -1 ? 0 : last_wrong - first_wrong + 1;

    first_wrong = min(first_wrong, first_zero);
    last_wrong = max(last_wrong, last_zero);

    return last_wrong - first_wrong + 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
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
int a[MAX_N], ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int j = 0;
    for (int i = 0; i < n / 2; i++)
    ans[j++] = a[i], ans[j++] = a[n - 1 - i];

    if (n & 1) ans[n - 1] = a[n / 2];

    for (int i = n - 1; i >= 0; i--)
    cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
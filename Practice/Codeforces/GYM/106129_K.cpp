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

#define MAX_N 1000
int ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, a, b; cin >> n >> a >> b;
    if (a + b > n + 1 || a + b < 3) {
        cout << "no\n";
        return 0;
    }

    bool rev = false;
    if (b == 1) {
        swap(a, b);
        rev = true;
    }

    int cur = n;
    for (int i = a - 1; i >= 0; i--) ans[i] = cur--;
    for (int i = n - b + 1; i < n; i++) ans[i] = cur--;
    for (int i = a; i < n - b + 1; i++) ans[i] = cur--;

    if (rev) reverse(ans, ans + n);
    cout << "yes\n";
    for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
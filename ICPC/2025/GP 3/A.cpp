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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
    }

    int ans = 0;
    for (int i = n; i >= 1; i--)
    if (sum % i == 0) break;
    else ans++;

    cout << ans << '\n';
    return 0;
}
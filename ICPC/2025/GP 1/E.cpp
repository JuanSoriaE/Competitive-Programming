#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define lli long long int
#define ld long double
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int ans = -1, aux;
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        if (ans == -1 && aux >= m)
            ans = i;
    }
    cout << ans << "\n";
    return 0;
}
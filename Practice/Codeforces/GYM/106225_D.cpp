#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 1001

int a[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        a[aux]++;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i] == i) continue;
    
        if (a[i] > i) ans += a[i] - i;
        else ans += a[i];
    }

    cout << ans << '\n';

    return 0;
}
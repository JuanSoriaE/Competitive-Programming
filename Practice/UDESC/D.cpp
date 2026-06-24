#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 200000

int a[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    while (n > 1) {
        for (int i = 0; i < n - 1; i += 2) {
            ans = max(ans, abs(a[i] - a[i + 1]));
            if (a[i] > a[i + 1])
                a[i + 1] = 0;
            else
                a[i] = 0;
        }

        int new_n = 0;
        for (int i = 0; i < n; i++)
        if (a[i]) a[new_n++] = a[i];

        n = new_n;
    }
    cout << ans << '\n';

    return 0;
}
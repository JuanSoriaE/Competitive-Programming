#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 10000000;

int f[MAX_N + 1];

int main() {
    int n; cin >> n;
    f[1] = 2;
    for (int i = 1; i <= n; i++) {
        if (!f[i]) f[i] = f[i - 1] + 1;
        if (f[i] <= n) f[f[i]] = 3 * i;
    }
    cout << f[n] << '\n';

    return 0;
}
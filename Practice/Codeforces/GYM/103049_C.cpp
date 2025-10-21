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

ll n, k, d, s;

bool is_possible() {
    return s * k <= d * n && d * n <= (n - k) * 100LL + s * k;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k >> d >> s;
    if (!is_possible()) {
        cout << "impossible\n";
        return 0;
    }

    long double ans = (static_cast<long double>(d) * n - static_cast<long double>(s) * k) / static_cast<long double>(n - k);
    cout << setprecision(250) << ans << '\n';

    return 0;
}
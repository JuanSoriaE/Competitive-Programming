#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;

    int total = 0;
    while (n--) {
        int a; cin >> a;
        total += a;
    }
    int paid = 0;
    while (m--) {
        int a; cin >> a;
        paid += a;
    }

    total = total + ceil(total, 10);
    cout << (paid >= total ? "YES" : "NO") << '\n';

    return 0;
}
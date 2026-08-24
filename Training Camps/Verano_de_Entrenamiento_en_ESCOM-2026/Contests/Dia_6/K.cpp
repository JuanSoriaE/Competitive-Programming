#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, d; cin >> n >> d;
    while (n--) {
        cout << "0 ";
        cout << d << ' ';
        cout << (d << 6) << ' ';
        cout << (d << 12) << ' ';
        cout << ((d << 6) + d) << ' ';
        cout << ((d << 12) + d) << ' ';
        cout << '\n';
    }
    return 0;
}
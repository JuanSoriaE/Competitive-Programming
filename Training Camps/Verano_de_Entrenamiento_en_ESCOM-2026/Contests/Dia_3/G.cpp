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
    int a, b; cin >> a >> b;
    int x = 0, y = 0, z = 0;
    int c = 0, d = 0, e = 0;
    while (a % 2 == 0) x++, a /= 2;
    while (a % 3 == 0) y++, a /= 3;
    while (a % 5 == 0) z++, a /= 5;

    while (b % 2 == 0) c++, b /= 2;
    while (b % 3 == 0) d++, b /= 3;
    while (b % 5 == 0) e++, b /= 5;


    cout << (a == b ? (abs(x - c) + abs(y - d) + abs(z - e)) : -1) << '\n';

    return 0;
}
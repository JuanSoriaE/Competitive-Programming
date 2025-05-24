#include <bits/stdc++.h>
using namespace std;

long long sum(long long l, long long r) {
    return (r * (r + 1)) / 2 - (l * (l - 1)) / 2;
}

void solve() {
    long long n, x, y; cin >> n >> x >> y;

    long long div_x = n / x,
              div_y = n / y,
              div_x_y = n / lcm(x, y);
    
    long long score = sum(n - (div_x - div_x_y - 1), n) - sum(1, div_y - div_x_y);

    cout << score << endl;
}

int main() {
    long long t; cin >> t;
    while (t--) solve();
    return 0;
}
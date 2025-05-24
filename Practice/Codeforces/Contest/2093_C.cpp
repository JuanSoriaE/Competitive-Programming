#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x == 1) return false;

    for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    int x, k;
    while (t--) {
        cin >> x >> k; // k always divisible by x
        cout << ((k == 2 && x == 1) || (k == 1 && is_prime(x)) ? "YES" : "NO") << "\n";
    }
    return 0;
}
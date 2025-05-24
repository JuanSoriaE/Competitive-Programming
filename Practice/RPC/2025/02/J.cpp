#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    int prev_a = 0, prev_b = 0;
    bool valid = true;
    while (n--) {
        int a, b; cin >> a >> b;

        if (a < prev_a || b < prev_b)
            valid = false;

        prev_a = a; prev_b = b;
    }
    cout << (valid ? "yes\n" : "no\n");

    return 0;
}
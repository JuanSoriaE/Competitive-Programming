#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n; cin >> n;
    cout << (long long)floor((-1 + sqrt(1 + 8 * n)) / 2) << "\n";
    return 0;
}
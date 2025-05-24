#include <bits/stdc++.h>
using namespace std;

long long solve() {
    int n, aux, mx = 0; cin >> n;
    long long even_sum = 0;
    bool odd = false, even = false;

    while (n--) {
        cin >> aux;

        mx = max(mx, aux);

        odd |= (aux % 2);
        even |= !(aux % 2);
        even_sum += aux - (aux % 2);
    }

    if (!odd || !even) return mx;
    return even_sum + 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}
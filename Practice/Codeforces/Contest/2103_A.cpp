#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

int solve() {
    int n, aux; cin >> n;
    set<int> s;
    while (n--) {
        cin >> aux;
        s.insert(aux);
    }
    return SZ(s);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
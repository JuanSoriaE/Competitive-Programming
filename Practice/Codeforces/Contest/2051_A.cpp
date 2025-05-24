#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    int res = 0, aux; cin >> aux;
    for (int i = 1; i < n; i++) {
        cin >> aux;
        if (v[i - 1] > aux) res += v[i - 1] - aux;
    }

    return res + v[v.size() - 1];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}
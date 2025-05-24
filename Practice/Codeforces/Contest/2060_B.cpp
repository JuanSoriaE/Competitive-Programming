#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, const int n, const int m) {
    // Check if permutation is repepetitive
    for (int i = 1; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[j] != a[i * n + j]) {
                cout << -1 << "\n";
                return;
            }

    for (int i = 0; i < n; i++)
        cout << a[i] + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;

    while (t--) {
        int n, m, aux; cin >> n >> m;
        vector<int> a(n * m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> aux;
                a[aux] = i;
            }
        
        solve(a, n, m);
    }

    return 0;
}
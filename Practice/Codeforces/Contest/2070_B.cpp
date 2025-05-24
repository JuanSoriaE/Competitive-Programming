#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;

    while (t--) {
        int n, x;
        ll k;
        cin >> n >> x >> k;
        string s; cin >> s;

        for (int i = 0; i < n; i++) {
            x += s[i] == 'L' ? -1 : 1;
            k--;

            if (!x) break;
        }

        if (x) {
            cout << 0 << "\n";
            continue;
        }

        ll res = 1;
        for (int i = 0; i < n; i++) {
            x += s[i] == 'L' ? -1 : 1;

            if (!x) {
                res += k / (i + 1);
                break;
            }
        }

        cout << res << "\n";
    }

    return 0;
}
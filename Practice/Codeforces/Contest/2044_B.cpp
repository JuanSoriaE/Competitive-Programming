#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        for (char &c : s) {
            if (c == 'w') continue;

            c = c == 'q' ? 'p' : 'q';
        }

        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}
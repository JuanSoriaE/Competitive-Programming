#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s;
    int a = 0, half = 0;
    while (m--) {
        cin >> s;
        bool in = false;
        for (char &c : s) {
            if (c == '.') {
                a += in;
                continue;
            }

            in = !in;
            half++;
        }
    }

    cout << (a + half / 2) << ".00\n";
    return 0;
}
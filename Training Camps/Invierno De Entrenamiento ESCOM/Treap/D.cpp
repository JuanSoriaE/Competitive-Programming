#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int A = s[0] == 'A', B = s[0] == 'B';

    for (int t = 1; t <= n; t++) {
        if (s[t] == 'A') A++;
        else B++;

        if (A >= B)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    
    return 0;
}
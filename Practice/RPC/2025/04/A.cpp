#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int(x.size()))

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int r, c; cin >> r >> c;
    vector<string> words(r);
    for (int i = 0; i < r; i++)
        cin >> words[i];

    int odds = 0;
    for (int i = 0; i < r; i++) {
        if ((c - SZ(words[i])) % 2) odds++;

        int l;
        if ((c - SZ(words[i])) % 2 == 0 || odds % 2)
            l = (c - SZ(words[i])) / 2;
        else l = (c - SZ(words[i])) / 2 + 1;

        for (int j = 0; j < l; j++)
            cout << ".";
        cout << words[i];
        for (int j = 0; j < c - SZ(words[i]) - l; j++)
            cout << ".";
        cout << "\n";
    }
    return 0;
}
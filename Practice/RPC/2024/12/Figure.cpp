#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    unordered_map<string, int> mp;
    string aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        mp[aux] = i;
    }

    int max_diff = 0;
    string fav;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        if (mp[aux] - i > max_diff) {
            max_diff = mp[aux] - i;
            fav = aux;
        }
    }

    cout << (max_diff == 0 ? "suspicious" : fav) << endl;

    return 0;
}
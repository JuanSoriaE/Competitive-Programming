#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    map<string, set<string>> mp;
    vector<vector<char>> dic = {
        {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
        {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
    };
    string word;
    while (n--) {
        cin >> word;
        string number = "";
        for (char &c : word) {
            int digit;
            for (int d = 0; d < 8; d++)
            if (find(dic[d].begin(), dic[d].end(), c) != dic[d].end())
                digit = d + 2;

            number += to_string(digit);
        }

        mp[number].insert(word);
    }

    while (m--) {
        string number; cin >> number;
        if (mp.find(number) == mp.end()) {
            cout << 0 << "\n";
            continue;
        }

        cout << mp[number].size() << " ";
        for (auto it = mp[number].begin(); it != prev(mp[number].end()); ++it)
            cout << *it << " ";
        cout << *prev(mp[number].end()) << "\n";
    }

    return 0;
}
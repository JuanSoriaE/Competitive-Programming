#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, r; cin >> n >> m >> r;
    vector<int> ranking(n + 1, 0);
    int p = 0;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (char &c : s) {
            ranking[i] += c == 'P';
            p += c == 'P';
        }
    }

    int cur = n;
    while (p--) {
        while (cur > 0 && ranking[cur] == 0) cur--;
        if (cur == 0) break;

        string s; cin >> s; cin >> s;
        ranking[cur]--;
        if (s.back() != '!') continue;

        int pass = s.size() - 9;
        int new_pos = cur - pass;

        if (cur == r) r = new_pos;
        else if (cur > r && new_pos <= r) r++;

        int aux = ranking[cur];
        for (int i = cur; i > new_pos; i--)
            ranking[i] = ranking[i - 1];
        ranking[new_pos] = aux;
    }

    cout << r << "\n";

    return 0;
}
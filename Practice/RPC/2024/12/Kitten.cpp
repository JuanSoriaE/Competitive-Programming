#include <bits/stdc++.h>
using namespace std;

void rotate_h(string &s) {
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        swap(s[l], s[r]);
        if (s[l] == 'b') s[l] = 'd';
        else if (s[l] == 'd') s[l] = 'b';
        else if (s[l] == 'p') s[l] = 'q';
        else if (s[l] == 'q') s[l] = 'p';

        if (l == r) {
            l++; r--;
            continue;
        }

        if (s[r] == 'b') s[r] = 'd';
        else if (s[r] == 'd') s[r] = 'b';
        else if (s[r] == 'p') s[r] = 'q';
        else if (s[r] == 'q') s[r] = 'p';

        l++; r--;
    }
}

void rotate_v(string &s) {
    for (char &c : s) {
        if (c == 'b') c = 'p';
        else if (c == 'p') c = 'b';
        else if (c == 'd') c = 'q';
        else if (c == 'q') c = 'd';
    }
}


void rotate_r(string &s) {
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        swap(s[l], s[r]);
        if (s[l] == 'q') s[l] = 'b';
        else if (s[l] == 'b') s[l] = 'q';
        else if (s[l] == 'd') s[l] = 'p';
        else if (s[l] == 'p') s[l] = 'd';

        if (l == r) {
            l++; r--;
            continue;
        }

        if (s[r] == 'q') s[r] = 'b';
        else if (s[r] == 'b') s[r] = 'q';
        else if (s[r] == 'd') s[r] = 'p';
        else if (s[r] == 'p') s[r] = 'd';

        l++; r--;
    }
}

int main() {
    string s, t; cin >> s >> t;
    int cnt[3] = {0};
    for (char &c : t) {
        if (c == 'h') cnt[0]++;
        else if (c == 'v') cnt[1]++;
        else cnt[2]++;
    }

    if (cnt[0] % 2 == 1) rotate_h(s);
    if (cnt[1] % 2 == 1) rotate_v(s);
    if (cnt[2] % 2 == 1) rotate_r(s);

    cout << s << "\n";

    return 0;
}
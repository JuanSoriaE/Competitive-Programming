#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int n;

int get_color_i(char &c) {
    if (c == 'R') return 5;
    else if (c == 'G') return 6;
    else if (c == 'B') return 7;
    else if (c == 'Y') return 8;
    return 9;
}

int get_number_i(char &c) {
    return c - '1';
}

bool valid(int mask, vector<string> cards, set<string> &st) {
    set<string> st2;
    for (string &card : cards) {
        int color_i = get_color_i(card[0]), number_i = get_number_i(card[1]);
        if (!(mask & (1 << color_i))) card[0] = '_';
        if (!(mask & (1 << number_i))) card[1] = '_';
        st2.insert(card);
    }

    return sz(st2) == sz(st);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    vector<string> cards(n);
    set<string> st;
    int known = 0;
    for (string &s : cards) {
        cin >> s;
        known |= (1 << get_color_i(s[0]));
        known |= (1 << get_number_i(s[1]));
        st.insert(s);
    }

    known = ~known;

    if (sz(st) == 1) {
        cout << "0\n";
        return 0;
    }

    int ans = INT_MAX, aux;
    for (int cur = 0; cur < (1 << 10); cur++) {
        int mask = cur | known;
        // Numeros
        if ((0b01111 & mask) == 0b01111) mask |= (1 << 4);
        else if ((0b10111 & mask) == 0b10111) mask |= (1 << 3);
        else if ((0b11011 & mask) == 0b11011) mask |= (1 << 2);
        else if ((0b11101 & mask) == 0b11101) mask |= (1 << 1);
        else if ((0b11110 & mask) == 0b11110) mask |= (1 << 0);

        // Colores
        if ((0b0111100000 & mask) == 0b0111100000) mask |= (1 << 9);
        else if ((0b1011100000 & mask) == 0b1011100000) mask |= (1 << 8);
        else if ((0b1101100000 & mask) == 0b1101100000) mask |= (1 << 7);
        else if ((0b1110100000 & mask) == 0b1110100000) mask |= (1 << 6);
        else if ((0b1111000000 & mask) == 0b1111000000) mask |= (1 << 5);

        if (valid(mask, cards, st))
            ans = min(ans, __builtin_popcount(cur));
    }
    cout << ans << '\n';

    return 0;
}
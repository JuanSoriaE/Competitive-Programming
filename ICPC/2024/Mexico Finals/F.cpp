#include <bits/stdc++.h>
using namespace std;

bool can_sit(int n, int k) {
    return (n + 2) / 3 <= k && k <= (n + 1) / 2; // lower <= k <= upper
}

int main() {
    int k, n; cin >> k >> n;
    if (!can_sit(n, k)) {
        cout << "*\n";
    } else {
        string s(n, '-');
        int i = 1;
        while (i < s.size()) {
            if (can_sit(n - i - 2, k - 1)) {
                s[i] = 'X';
                k--;
                i += 3;
            } else
                i--;
        }

        if (k != 0) s[s.size() - 1] = 'X';

        cout << s << "\n";
    }
    return 0;
}
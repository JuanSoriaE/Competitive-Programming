#include <bits/stdc++.h>
using namespace std;

vector<int> get_divisors(int x) {
    vector<int> divisors(floor(sqrt(x)) * 2 + 1, 0);
    int i = 0, j = divisors.size() - 1;
    for (int k = 1; k * k <= x; k++) {
        if (x % k == 0) {
            divisors[i++] = k;
            if (k != x / k)
                divisors[j--] = x / k;
        }
    }

    return divisors;
}

int main() {
    string s; cin >> s;
    vector<int> divisors = get_divisors(s.size());
    for (int x : divisors) {
        if (x == 0) continue;
        string t = s.substr(0, x);
        bool flag = true;
        for (int i = 1; i < s.size() / x; i++)
            if (t != s.substr(i * x, x)) {
                flag = false;
                break;
            }

        if (flag) {
            cout << t << "\n";
            return 0;
        }
    }

    return 0;
}
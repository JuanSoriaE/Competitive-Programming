#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

bool query(int u, int k) {
    cout << "? " << u << ' ' << k << endl;
    cout.flush();
    string res; cin >> res;
    return res == "Yes";
}

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "! 1 1" << endl;
        cout.flush();
        return 0;
    }

    int c = n;
    for (int u = 1; u <= n && c > 1; u++) {
        if (query(u, c - 1)) {
            c--;
            while (c - 1 >= 1 && query(u, c - 1))
                c--;
        }
    }

    vector<int> ans(c);
    int j = 0;
    for (int u = 1; u <= n; u++)
    if (query(u, c)) ans[j++] = u;

    cout << "! " << c << ' ';
    for (int &i : ans) cout << i << ' ';
    cout << endl;
    cout.flush();

    return 0;
}
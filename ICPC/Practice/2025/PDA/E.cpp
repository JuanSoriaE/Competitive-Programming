#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

pair<int, int> aux(int &a, int &b, char &c) {
    if (c == 'E') return {(a + b) / 2, (a + b) / 2};
    if (c == 'A') return {INT_MIN, (a + b) / 2 - ((a + b) & 1 ? 0 : 1)};
    return {(a + b) / 2 + 1, INT_MAX};
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    int a, b; char c;
    cin >> a >> b >> c;

    if (((a + b) & 1) && c == 'E') {
        cout << "*\n";
        return 0;
    }

    auto [l, r] = aux(a, b, c);
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        if (((a + b) & 1) && c == 'E') {
            cout << "*\n";
            return 0;
        }

        auto [l1, r1] = aux(a, b, c);
        if (min(r, r1) < max(l, l1)) {
            cout << "*\n";
            return 0;
        }

        l = max(l, l1);
        r = min(r, r1);
    }

    cout << l << ' ' << r << '\n';

    return 0;
}
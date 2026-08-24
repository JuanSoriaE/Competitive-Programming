#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s; cin >> s;
    const int n = sz(s);
    int l = 0, r = n - 1;
    string a = "";

    while (r - l >= 3) {
        if (s[l] == s[r])
            a += s[l], l++, r--;
        else if (s[l] == s[r - 1])
            a += s[l], l++, r -= 2;
        else {
            a += s[l + 1];
            if (s[l + 1] == s[r])
                r--;
            else
                r -= 2;
            l += 2;
        }
    }

    cout << a;
    if (l <= r) cout << s[l];
    for (int i = sz(a) - 1; i >= 0; i--)
        cout << a[i];
    cout << '\n';

    return 0;
}
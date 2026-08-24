// https://cses.fi/problemset/task/1733
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 1000000;

int lps[MAX_N];
void prefix_function(const string &s) {
    const int n = sz(s);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s; cin >> s;
    int n = sz(s);
    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j && s[j] != s[i])
            j = lps[j - 1];
        if (s[j] == s[i]) j++;
        lps[i] = j;
    }

    for (int cur = n - 1; lps[cur] > 0; cur = lps[cur] - 1)
        cout << n - lps[cur] << ' ';
    cout << n << '\n';

    return 0;
}
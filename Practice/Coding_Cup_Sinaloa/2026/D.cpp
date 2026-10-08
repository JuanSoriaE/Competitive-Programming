#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_M = 100000;

int n, m;

int lps[MAX_M];
void prefix_function(const vector<int> &b) {
    const int n = sz(b);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j && b[i] != b[j])
            j = lps[j - 1];
        if (b[i] == b[j]) j++;
        lps[i] = j;
    }
}

int kmp(const vector<int> &a, const vector<int> &b) {
    const int n = sz(a), m = sz(b);

    int res = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j && a[i] != b[j])
            j = lps[j - 1];
        if (a[i] == b[j]) j++;
        if (j == m) {
            res++;
            j = lps[j - 1];
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    vector<int> a(n), b(m);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "J" || s == "Q" || s == "K")
            a[i] = 10;
        else
            a[i] = stoi(s);
    }

    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s == "J" || s == "Q" || s == "K")
            b[i] = 10;
        else
            b[i] = stoi(s);
    }

    vector<int> aux_0, aux_1;
    for (int i = 0; i < n - 1; i++) {
        if (i & 1) aux_1.push_back(21 - (a[i] + a[i + 1]));
        else aux_0.push_back(21 - (a[i] + a[i + 1]));
    }

    prefix_function(b);
    cout << kmp(aux_0, b) + kmp(aux_1, b) << '\n';

    return 0;
}
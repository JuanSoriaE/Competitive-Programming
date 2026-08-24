#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;

// Compute KMP Prefix function (Longest Prefix Suffix)
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

// Search all the occurrences of pattern p in text t
vector<int> kmp(const string &t, const string &p) {
    const int n = sz(t), m = sz(p);

    vector<int> matches;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j && t[i] != p[j])
            j = lps[j - 1];
        if (t[i] == p[j]) j++;
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        }
    }

    return matches;
}

// Count the number of occurrences of each prefix
vector<int> prefix_occurrences(const string &s) {
    prefix_function(s);
    const int n = sz(s);

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
        cnt[lps[i]]++;
    for (int i = n - 1; i; i--)
        cnt[lps[i - 1]] += cnt[i];
    for (int i = 0; i <= n; i++)
        cnt[i]++;

    return cnt;
}

// Compute the length of all the borders of s (prefixes that are suffixes of s)
vector<int> borders(const string &s) {
    prefix_function(s);
    const int n = sz(s);
    vector<int> borders;
    for (int i = lps[n - 1]; i; i = lps[i - 1])
        borders.push_back(i);
    return borders;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
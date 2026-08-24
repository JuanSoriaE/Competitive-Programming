// https://codeforces.com/problemset/problem/471/D
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;
constexpr int MAX_W = 200000;

int a[MAX_N - 1], b[MAX_W - 1];
int lps[MAX_W - 1];

void prefix_function(const int &n) {
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j && b[i] != b[j])
            j = lps[j - 1];
        if (b[i] == b[j]) j++;
        lps[i] = j;
    }
}

// Searches all the occurrences of pattern p in text t
int kmp(const int &n, const int &m) {
    int matches = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j && a[i] != b[j])
            j = lps[j - 1];
        if (a[i] == b[j]) j++;
        if (j == m) {
            matches++;
            j = lps[j - 1];
        }
    }

    return matches;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, w; cin >> n >> w;
    if (w > n) {
        cout << "0\n";
        return 0;
    }
    if (w == 1) {
        cout << n << '\n';
        return 0;
    }

    int prev; cin >> prev;
    for (int i = 0; i < n - 1; i++)  {
        int aux; cin >> aux;
        a[i] = aux - prev;
        prev = aux;
    }

    cin >> prev;
    for (int i = 0; i < w - 1; i++) {
        int aux; cin >> aux;
        b[i] = aux - prev;
        prev = aux;
    }

    n--, w--;

    prefix_function(w);
    cout << kmp(n, w) << '\n';
    
    return 0;
}
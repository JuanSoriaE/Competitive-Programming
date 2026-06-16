#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 200000

int a[MAX_N];
ll b[MAX_N];
ll b_aux[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;

    string aux = "";
    for (char c : s)
    if (c != '=') aux += c;

    fill(b_aux, b_aux + sz(aux) + 1, 1);
    for (int i = 1; i < sz(aux) + 1; i++) {
        if (aux[i - 1] == '<')
            b_aux[i] = b_aux[i - 1] + 1;
    }

    for (int i = sz(aux) - 1; i >= 0; i--) {
        if (aux[i] == '>')
            b_aux[i] = max(b_aux[i + 1] + 1, b_aux[i]);
    }

    aux += 'a'; s += 'a';
    int s_i = 0, b_i = 0;
    for (int i = 0; i < sz(aux); i++) {
        b[b_i++] = b_aux[i];
        while (s[s_i] != aux[i]) {
            b[b_i++] = b_aux[i];
            s_i++;
        }
        s_i++;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    cout << sum << '\n';

    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';

    return 0;
}
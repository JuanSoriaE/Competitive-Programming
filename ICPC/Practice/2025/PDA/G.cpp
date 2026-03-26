#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_AT 100

int base_cat[MAX_AT], base_gata[MAX_AT];
void compute_bases() {
    int prefix_cat = 0, prefix_gata = 0;
    for (int i = 1; i <= MAX_AT; i++) {
        prefix_cat += i;
        prefix_gata += i * (i + 1) / 2;
        base_cat[i - 1] = prefix_cat;
        base_gata[i - 1] = prefix_gata;
    }
}

int decomposition_cat[MAX_AT];
void decompose_cat(int n) {
    for (int i = MAX_AT - 1; i >= 0; i--) {
        int p = 0;
        while (base_cat[i] <= n) {
            n -= base_cat[i];
            p++;
        }

        decomposition_cat[i] = p;
    }
}

int decomposition_gata[MAX_AT];
void decompose_gata(int n) {
    for (int i = MAX_AT - 1; i >= 0; i--) {
        int p = 0;
        while (base_gata[i] <= n) {
            n -= base_gata[i];
            p++;
        }

        decomposition_gata[i] = p;
    }
}

void solve() {
    int g, c; cin >> g >> c;
    decompose_cat(c);
    decompose_gata(g);

    string ans = "A";
    for (int i = 0; i < MAX_AT; i++) {
        ans += "TA";
        for (int j = 0; j < decomposition_cat[i]; j++)
            ans += 'C';
        for (int j = 0; j < decomposition_gata[i]; j++)
            ans += 'G';
    }

    reverse(all(ans));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    compute_bases();
    int q; cin >> q;
    while (q--) solve();
    return 0;
}
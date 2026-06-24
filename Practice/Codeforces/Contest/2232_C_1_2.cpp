#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 200000

int x, s, I;
int next_I[MAX_N], ans, e_open;

void introvert() { x--; e_open += s - 1; ans++; }
void extrovert() { e_open--; ans++; }

void reset() { ans = e_open = I = 0; }

void solve() {
    reset();
    int n; cin >> n >> x >> s;
    string u; cin >> u;

    int total_I = 0, last_I = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (u[i] == 'I') total_I++, last_I = i;
        next_I[i] = last_I;
    }

    for (int i = 0; i < n; i++) {
        char &c = u[i];
        if (!e_open && !x) break;
        if (c == 'I') I++;

        if (c == 'I' && x)
            introvert();
        else if (c == 'E' && e_open)
            extrovert();
        else if (c == 'A') {
            if (!e_open && x)
                introvert();
            else if (!x && e_open)
                extrovert();
            else { // Can be I or E
                int rem_I = total_I - I;
                if (rem_I < x)
                    introvert();
                else {
                    int mid_E_A = next_I[i] - i;
                    if (mid_E_A > e_open)
                        (x ? introvert() : void());
                    else
                        (e_open ? extrovert() : void());
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
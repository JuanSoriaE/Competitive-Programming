#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 1000000

int p[MAX_N + 1];
bool vst[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    int cycles = 0;
    for (int i = 1; i <= n; i++) {
        if (vst[i]) continue;

        cycles++;
        int cur = i;
        while (!vst[cur]) {
            vst[cur] = true;
            cur = p[cur];
        }
    }

    int mini_to_sort = n - cycles;
    if (n & 1)
        cout << (mini_to_sort & 1 ? "Petr" : "Um_nik") << '\n';
    else
        cout << (mini_to_sort & 1 ? "Um_nik" : "Petr") << '\n';

    return 0;
}
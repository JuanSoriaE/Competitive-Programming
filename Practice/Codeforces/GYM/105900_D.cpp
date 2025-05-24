#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int rl, hl, r, h; cin >> rl >> hl >> r >> h;
    ll vol_lucas = 3 * rl * rl * hl;
    ll vol = r * r * h + 2 * r * r * r;
    if (vol_lucas > vol) cout << "Injusto\n";
    else cout << "Justo\n";

    return 0;
}
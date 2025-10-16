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
    int n; cin >> n;
    set<int> towers;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        towers.insert(aux);
    }

    int cur = 0, turn = 0;
    bool has_advantage = 0;
    for (int tower : towers) {
        if (tower - cur > 1) {
            has_advantage = 1;
            break;
        }

        turn = (turn + 1) % 2;
        cur++;
    }

    cout << (has_advantage ? (turn ? "Bobius" : "Alicius") : (n % 2 ? "Alicius" : "Bobius")) << "\n";

    return 0;
}
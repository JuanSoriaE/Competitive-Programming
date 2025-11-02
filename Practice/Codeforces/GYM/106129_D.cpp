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
    int min_x, min_y, max_x, max_y;
    min_x = min_y = INT_MAX;
    max_x = max_y = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        min_x = min(min_x, x); min_y = min(min_y, y);
        max_x = max(max_x, x); max_y = max(max_y, y);
    }

    cout << "4\n";
    cout << min_x << ' ' << max_y << '\n';
    cout << min_x << ' ' << min_y << '\n';
    cout << max_x << ' ' << min_y << '\n';
    cout << max_x << ' ' << max_y << '\n';
    return 0;
}
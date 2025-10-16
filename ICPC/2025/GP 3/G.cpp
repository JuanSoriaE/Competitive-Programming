#include <bits/stdc++.h>
using namespace std;

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
    int t; cin >> t;

    ld h1, h2, b, ans;
    while (t--) {
        cin >> h1 >> h2 >> b;
        cout << ceil((log(h2) - log(h1)) / (log(b - 1) - log(b))) << "\n";
    }
    return 0;
}
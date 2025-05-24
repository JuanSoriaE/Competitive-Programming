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
    string s; cin >> s;
    cin >> s; cin >> s;
    if (s[0] == 'T') cout << "Staraptor";
    else if (s[0] == 'S') cout << "Luxray";
    else cout << "Torterra";
    cout << ", eu escolho voce!";

    return 0;
}
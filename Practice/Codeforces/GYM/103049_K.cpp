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
    string s, t;
    getline(cin, s); getline(cin, t);
    map<char, int> mp;
    for (char &c : s) mp[c]++;
    for (char &c : t) mp[c]--;

    for (auto &[c, cnt] : mp)
    if (cnt < 0) cout << c;
    cout << '\n';

    return 0;
}
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
    vector<int> v(60, 0);
    int k = 10;
    for (int i = 59; k > 0; i--, k--) {
        v[i] = 1;
    }
    int cnt = 0;
    do {
        cnt++;
    } while (next_permutation(all(v)));
    cout << cnt << "\n";
    return 0;
}
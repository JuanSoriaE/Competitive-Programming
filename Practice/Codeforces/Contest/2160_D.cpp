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

#define MAX_N 300
int ans[2 * MAX_N + 1];

void solve() {
    int n; cin >> n;
    vector<int> unknown, known;
    unknown.push_back(1);
    for (int i = 2; i <= 2 * n; i++) {
        cout << "? " << sz(unknown) + 1 << ' ' << i;
        for (int &j : unknown) cout << ' ' << j;
        cout << endl; cout.flush();

        int res; cin >> res;
        if (!res) unknown.push_back(i);
        else {
            ans[i] = res;
            known.push_back(i);
        }
    }

    for (int &i : unknown) {
        cout << "? " << sz(known) + 1 << ' ' << i;
        for (int &j : known) cout << ' ' << j;
        cout << endl; cout.flush();

        int res; cin >> res;
        ans[i] = res;
    }

    cout << "! ";
    for (int i = 1; i <= 2 * n; i++)
    cout << ans[i] << ' ';
    cout << endl; cout.flush();
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
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

#define MAX_N 100

char ans[MAX_N][2 * MAX_N - 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    fill(ans[0], ans[0] + 2 * n - 1, '.');
    ans[0][n - 1] = '*';
    for (int i = 0; i < 2 * n - 1; i++) cout << ans[0][i];
    cout << '\n';

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            bool l = i > 0 && j > 0 && ans[i - 1][j - 1] == '*';
            bool r = i > 0 && j < 2 * n - 2 && ans[i - 1][j + 1] == '*';
            ans[i][j] = l != r ? '*' : '.';
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}
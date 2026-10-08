#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

vector<string> rotate(const vector<string> &mat) {
    const int n = sz(mat), m = sz(mat[0]);
    vector<string> res(m, string(n, ' '));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        res[j][n - 1 - i] = mat[i][j];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    for (string &s : mat) cin >> s;

    int ans = 0;
    vector<string> aux = mat;
    for (int i = 0; i < 4; i++) {
        if (aux == mat) ans++;
        aux = rotate(aux);
    }

    aux = mat;
    for (int i = 0; i < n; i++)
    reverse(all(aux[i]));

    for (int i = 0; i < 4; i++) {
        if (aux == mat) ans++;
        aux = rotate(aux);
    }

    cout << ans << '\n';

    return 0;
}
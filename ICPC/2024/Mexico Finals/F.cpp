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

bool is_possible(int n, int k) {
    return ceil(n, 3) <= k && k <= ceil(n, 2);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k; cin >> k >> n;
    if (!is_possible(n, k)) {
        cout << "*\n";
        return 0;
    }

    string ans(n, '-');
    int i = 1, cnt = 0, k_aux = k;
    while (i < n) {
        if (is_possible(n - i - 2, k_aux - 1)) ans[i] = 'X', i += 3;
        else ans[i - 1] = 'X', i += 2;
        k_aux--;
        cnt++;
    }
    if (cnt != k) ans[n - 1] = 'X';

    cout << ans << '\n';

    return 0;
}
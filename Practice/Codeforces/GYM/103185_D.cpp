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

#define MAX_A 100000
#define EXTRA 30
int cnt[MAX_A + EXTRA] = {0};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    if (n == 1) {
        cout << "N\n";
        return 0;
    }

    int aux = 0;
    for (int i = 0; i < MAX_A + EXTRA - 1; i++) {
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;
        aux += cnt[i];
    }

    cout << (aux <= 2 ? 'Y' : 'N') << '\n';

    return 0;
}
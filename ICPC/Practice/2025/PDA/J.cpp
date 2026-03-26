#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_P 2000
int a[MAX_P];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int p, d; cin >> p >> d;
    fill(a, a + p, 0);
    for (int i = 0; i < d; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
            a[j]++;

        sort(a, a + k);
    }

    cout << *max_element(a, a + p) << '\n';

    return 0;
}
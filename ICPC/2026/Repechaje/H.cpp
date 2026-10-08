#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    int mini = INT_MAX, maxi = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mini = min(mini, a);
        maxi = max(maxi, a);
    }
    cout << (maxi - mini) << '\n';

    return 0;
}
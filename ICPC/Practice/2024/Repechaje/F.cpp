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
    multiset<int> a;
    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < 4; i++) {
        int x; cin >> x;
        a.erase(a.find(x));
    }
    cout << *a.begin() << '\n';

    return 0;
}
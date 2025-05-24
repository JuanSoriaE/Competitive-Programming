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

void solve() {
    ll n, aux; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> hp;
    while (n--) {
        cin >> aux;
        hp.push(aux);
    }

    while (sz(hp) > 1) {
        ll a = hp.top(); hp.pop();
        ll b = hp.top(); hp.pop();
        hp.push(a + b - 1);
    }

    cout << hp.top() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
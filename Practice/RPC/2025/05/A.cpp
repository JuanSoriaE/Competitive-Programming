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

ll solve() {
    int n; cin >> n;
    int _n = n, aux;
    priority_queue<ll, vector<ll>, greater<ll>> min_heap;
    while (_n--) { cin >> aux; min_heap.push(aux); }

    ll sum, res = 0;
    while (sz(min_heap) >= 2) {
        sum = min_heap.top(); min_heap.pop();
        sum += min_heap.top(); min_heap.pop();
        res += sum;
        min_heap.push(sum);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
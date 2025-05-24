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

// Floor and Ceiling Log2
int log2_floor(int x) {
    return 31 - __builtin_clz(x);
}
int log2_floor(ll x) {
    return 63 - __builtin_clzll(x);
}
int log2_ceiling(int x) {
    int floor = log2_floor(x);
    return floor + !((1 << floor) == x);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll bin_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, i; cin >> n >> i;
    int aux, x_i;
    ll div = 0;
    while (n--) {
        cin >> aux;
        i--;

        if (!i) x_i = aux;

        div = (div + bin_pow(2, aux)) % MOD;
    }

    ll num = bin_pow(2, x_i);
    div = bin_pow(div, MOD - 2);

    cout << ((num * div) % MOD) << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, aux, lp = 0, ln = 0, mp = 0, mn = 0; cin >> n;
    while (n--) {
        cin >> aux;

        ll a, b;
        if (aux > 0) {
            a = mn + aux;
            b = mp + aux - lp;

            if (a >= b && a > mp) {
                mp = a;
                lp = aux;
            }
            if (b >= a && b > mp) {
                mp = b;
                lp = aux;
            }
        } else {
            a = mp + aux;
            b = mn + aux - ln;

            if (a >= b && a > mn) {
                mn = a;
                ln = aux;
            }
            if (b >= a && b > mn) {
                mn = b;
                ln = aux;
            }
        }
    }

    cout << mp << "\n";
    
    return 0;
}
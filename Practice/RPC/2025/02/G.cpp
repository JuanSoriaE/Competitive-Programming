#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int total = 0;
    vector<int> rem(5, 0);
    long double p;
    int p_int;

    while (n--) {
        p; cin >> p;
        p_int = (int) 100 * p + 0.5;
        total += p_int;
        rem[p_int % 5]++;
    }
    
    int min_3_4 = min(rem[3], rem[4]);

    total -= rem[1] + 2 * rem[2];
    total -= 2 * min_3_4;;

    rem[3] -= min_3_4;
    rem[4] -= min_3_4;

    total -= rem[3] / 2;
    total -= 2 * (rem[4] / 3);
    
    cout << (total / 100) << "." << ((total % 100) / 10) << (total % 10) << "\n";

    return 0;
}
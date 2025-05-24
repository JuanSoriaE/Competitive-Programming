#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, n_aux; cin >> n;
    int d;
    string code = "";
    vector<bool> vst(2 * n + 1);

    n_aux = n;    
    while (n_aux--) {
        cin >> d;
        code += to_string(d) + " ";
        vst[d] = true;
    }

    n_aux = n - 1;
    while (n_aux--) {
        for (int i = 0; i < n - 1; i++)
            cin >> d;
        cin >> d;
        code += to_string(d) + " ";
        vst[d] = true;
    }

    for (int i = 1; i < 2 * n + 1; i++) {
        if (!vst[i]) {
            d = i;
            break;
        }
    }

    cout << d << " " << code << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
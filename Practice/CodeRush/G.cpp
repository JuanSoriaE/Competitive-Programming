#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, aux; cin >> n;
    int s = 0, n_s = 0;
    while (n--) {
        cin >> aux;
        if (aux % 2 == 0) s++;
        else n_s++;
    }
    cout << (n_s >= s ? "Notbastian" : "Sebastian") << "\n";
    return 0;
}
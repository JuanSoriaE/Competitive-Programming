#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    int corner_endpoints = 0;
    if ((x1 == 0 || x1 == 2024) && (y1 == 0 || y1 == 2024))
        corner_endpoints++;
    if ((x2 == 0 || x2 == 2024) && (y2 == 0 || y2 == 2024))
        corner_endpoints++;
    
    cout << (2 - corner_endpoints) << "\n";
    return 0;
}
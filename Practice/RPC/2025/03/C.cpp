#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int a, b; cin >> a >> b;

    int i = sqrt(a), ans = 0;
    for (;i * i <= b; i++)
        if (i * i >= a) ans += 15;

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k, a; cin >> n >> k;
    unordered_set<int> win;
    int ans = 0;
    while (n--) {
        cin >> a;

        win.insert(a);
        if (win.size() > k) {
            ans++;
            win.clear();
            win.insert(a);
        }
    }

    cout << (ans + 1) << "\n";

    return 0;
}
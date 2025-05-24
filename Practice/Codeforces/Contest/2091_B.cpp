#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve() {
    int n, x, aux; cin >> n >> x;
    vector<int> v;
    
    int ans = 0;
    while (n--) {
        cin >> aux;

        if (aux >= x) ans++;
        else v.push_back(aux);
    }

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0, cnt = 1; i < v.size(); i++, cnt++)
        if (v[i] * cnt >= x) {
            ans++;
            cnt = 0;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
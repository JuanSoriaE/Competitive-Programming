#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve() {
    int n, aux; cin >> n;
    int cnt[10] = {0};

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        cnt[aux]++;

        if (ans == 0 && cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1)
            ans = i + 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
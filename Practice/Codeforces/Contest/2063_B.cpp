#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &arr, int l, int r) {
    
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << solve(arr, l, r) << "\n";
    }

    return 0;
}
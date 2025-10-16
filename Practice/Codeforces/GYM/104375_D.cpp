#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

int n;
vector<int> nums;

int binary_search(int k, auto comp) {
    int l = 0, r = sz(nums) - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (comp(nums[mid], k)) r = mid - 1;
        else l = mid + 1;
    }

    return l;
}

int smaller_equal(int k) {
    int l = 0, r = sz(nums) - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (comp(nums[mid], k)) r = mid - 1;
        else l = mid + 1;
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> n >> q;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(all(nums));

    auto greater = [](int &a, int &b) -> bool { return a > b }
    auto greater_equal = [](int &a, int &b) -> bool { return a >= b }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int k; cin >> k;

            
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

map<int, int> mp;
multiset<int> mats;

int get_ans(int id) {
    if (mats.size() == 1) return 1;

    int w = mp[id];
    mats.erase(mats.find(w));

    int total = 0;
    int res = 0, first = -1;
    if (*mats.begin() <= w) {
        total = first = *mats.begin();
        res = 1;
        mats.erase(mats.begin());
    }

    auto it = mats.lower_bound(total);
    while (it != mats.end() && (total + *it) <= w) {
        total += *it;
        res++;
        it = mats.lower_bound(total);
    }

    total += w;
    res++;

    it = mats.lower_bound(total);
    while (it != mats.end()) {
        total += *it;
        res++;
        it = mats.lower_bound(total);
    }


    if (first != -1) mats.insert(first);
    mats.insert(w);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int w; cin >> w;
        mp[i] = w;
        mats.insert(w);
    }

    while (q--) {
        char op; cin >> op;
        if (op == '+') {
            int w, id; cin >> w >> id;
            mp[id] = w;
            mats.insert(w);
        } else if (op == '-') {
            int id; cin >> id;
            mats.erase(mats.find(mp[id]));
        } else {
            int id; cin >> id;
            cout << get_ans(id) << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define ll long long
#define fi first
#define se second

ll dist(vector<ll> &p, vector<ll> &q) {
    return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]) + (p[2] - q[2]) * (p[2] - q[2]);
}

bool is_cube(vector<vector<ll>> &P) {
    map<ll, ll> mp;
    for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 8; j++) {
        ll d = dist(P[i], P[j]);
        mp[d]++;

        if (mp.size() > 3 || mp[d] > 12)
            return false;
    }

    if (mp.size() != 3)
        return false;
 
    return mp.begin()->se == 12 && next(mp.begin())->se == 12 && next(next(mp.begin()))->se == 4;
}

bool dfs(vector<vector<ll>> &P, int i) {
    if (i == 8)
        return is_cube(P);

    do {
        if (dfs(P, i + 1))
            return true;
    } while (next_permutation(all(P[i])));

    return false;
}
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<vector<ll>> P(8);
    for (int i = 0; i < 8; i++) {
        int x, y, z; cin >> x >> y >> z;
        vector<ll> p = {x, y, z};
        sort(all(p));

        P[i] = p;
    }

    if (dfs(P, 0)) {
        cout << "YES\n";
        for (auto p : P)
            cout << p[0] << " " << p[1] << " " << p[2] << "\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
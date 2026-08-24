#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

pair<bool, vector<pair<int, char>>> valid_seg(vector<ll> &a, int l, int r) {
    if (l == r) return {true, {}};

    vector<ll> aux(r - l + 1);
    for (int i = 0; i < sz(aux); i++)
        aux[i] = a[i + l];

    ll maxi = *max_element(aux.begin(), aux.end());
    int j = -1;
    for (int i = 0; i < sz(aux) && j == -1; i++) {
        if (aux[i] == maxi && (
            (i - 1 >= 0 && aux[i - 1] < maxi) ||
            (i + 1 < sz(aux) && aux[i + 1] < maxi)
        )) j = i;
    }

    if (j == -1) return {false, {}};

    vector<pair<int, char>> L(j, {0, 'L'});
    vector<pair<int, char>> R(sz(aux) - j - 1, {0, 'R'});

    if (j - 1 >= 0 && aux[j - 1] < maxi) {
        vector<pair<int, char>> res(L.begin(), L.end());
        res.insert(res.end(), R.begin(), R.end());
        for (int i = 0; i < sz(L); i++)
            res[i].first = l + j - i;
        for (int i = sz(L); i < sz(res); i++)
            res[i].first = l;
        return {true, res};
    } else {
        vector<pair<int, char>> res(R.begin(), R.end());
        res.insert(res.end(), L.begin(), L.end());
        for (int i = 0; i < sz(R); i++)
            res[i].first = j + l;
        for (int i = sz(R); i < sz(res); i++)
            res[i].first = l + j - (i - sz(R));
        return {true, res};
    }

    return {false, {}};
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    int k; cin >> k;
    vector<ll> b(k);
    for (ll &i : b) cin >> i;

    ll pref = 0;
    int l = 0, j = 0;
    vector<pair<int, int>> segs;
    for (int r = 0; r < n; r++) {
        pref += a[r];
        if (pref == b[j]) {
            segs.push_back({l, r});
            pref = 0;
            l = r + 1;
            j++;
        }
    }

    if (sz(segs) != k || l != n) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<pair<int, char>>> ans;
    for (auto &[l, r] : segs) {
        auto res = valid_seg(a, l, r);
        if (!res.first) {
            cout << "NO\n";
            return 0;
        }

        ans.push_back(res.second);
    }

    int dec = 0;
    cout << "YES\n";
    for (auto &res : ans) {
        int sum = 0;
        for (auto &[i, c] : res) {
            sum++;
            cout << (i + 1 - dec) << ' ' << c << '\n';
        }
        dec += sum;
    }

    return 0;
}
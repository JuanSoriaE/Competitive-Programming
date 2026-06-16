#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100000

struct FenwickTree {
    vector<map<int, int>> bit;
    int n;

    FenwickTree(const int &n) : n(n), bit(n, map<int, int>()) {}

    void add(int v, int val) {
        for (; v < n; v = v | (v + 1))
            bit[v][val]++;
    }
    void remove(int v, int val) {
        for (; v < n; v = v | (v + 1))
            bit[v][val]--;
    }
    int query(int v, int val) {
        int ret = 0;
        for (; v >= 0; v = (v & (v + 1)) - 1)
            ret += bit[v][val];
        return ret;
    }
};

// time, type, val, og i, version
struct Data {
    int time, type, val, i, version;
};
Data a[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].type >> a[i].time >> a[i].val;
        a[i].i = i;
    }

    sort(a, a + n, [](const Data &a, const Data &b) {
        return a.time < b.time;
    });
    for (int i = 0; i < n; i++)
        a[i].version = i;

    sort(a, a + n, [](const Data &a, const Data &b) {
        return a.i < b.i;
    });

    FenwickTree f(n);
    for (int i = 0; i < n; i++) {
        if (a[i].type == 1)
            f.add(a[i].version, a[i].val);
        else if (a[i].type == 2)
            f.remove(a[i].version, a[i].val);
        else
            cout << f.query(a[i].version, a[i].val) << '\n';
    }

    return 0;
}
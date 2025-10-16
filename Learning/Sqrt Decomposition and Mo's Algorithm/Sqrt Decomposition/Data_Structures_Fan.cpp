// https://codeforces.com/contest/1872/problem/E
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

#define MAX_N 100000
#define BLOCK_SIZE 317

int a[MAX_N], XOR[BLOCK_SIZE][2];
bool rev[BLOCK_SIZE];
string s;
int n;

void update(int l, int r) {
    while (l <= r && l % BLOCK_SIZE != 0) {
        int id = l / BLOCK_SIZE;
        XOR[id][0] ^= a[l];
        XOR[id][1] ^= a[l];
        s[l] = s[l] == '0' ? '1' : '0';
        l++;
    }
    while (l + BLOCK_SIZE - 1 <= r) {
        int id = l / BLOCK_SIZE;
        rev[id] ^= 1;
        swap(XOR[id][0], XOR[id][1]);
        l += BLOCK_SIZE;
    }
    while (l <= r) {
        int id = l / BLOCK_SIZE;
        XOR[id][0] ^= a[l];
        XOR[id][1] ^= a[l];
        s[l] = s[l] == '0' ? '1' : '0';
        l++;
    }
}
int query(int g) {
    int l = 0, r = n - 1;
    int res = 0;
    while (l <= r && l % BLOCK_SIZE != 0) {
        int id = l / BLOCK_SIZE, f = g ^ rev[id];
        if (s[l] == (f ? '1' : '0')) res ^= a[l];
        l++;
    }
    while (l + BLOCK_SIZE - 1 <= r) {
        int id = l / BLOCK_SIZE;
        res ^= XOR[id][g];
        l += BLOCK_SIZE;
    }
    while (l <= r) {
        int id = l / BLOCK_SIZE, f = g ^ rev[id];
        if (s[l] == (f ? '1' : '0')) res ^= a[l];
        l++;
    }
    return res;
}

void solve() {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        XOR[i][0] = 0; XOR[i][1] = 0;
        rev[i] = 0;
    }

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') XOR[i / BLOCK_SIZE][0] ^= a[i];
        else XOR[i / BLOCK_SIZE][1] ^= a[i];
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            update(l - 1, r - 1);
        } else {
            int g; cin >> g;
            cout << query(g) << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
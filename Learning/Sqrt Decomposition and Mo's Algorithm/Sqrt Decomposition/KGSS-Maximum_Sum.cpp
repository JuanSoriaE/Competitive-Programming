// https://www.spoj.com/problems/KGSS/
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

int a[MAX_N];
int b[BLOCK_SIZE][2] = {};

void update(int i, int x) {
    a[i] = x;
    int mx1 = 0, mx2 = 0, id = i / BLOCK_SIZE;
    for (int j = id * BLOCK_SIZE; j < (id + 1) * BLOCK_SIZE; j++) {
        if (a[j] >  mx1) {
            mx2 = mx1;
            mx1 = a[j];
        } else if (a[j] > mx2) {
            mx2 = a[j];
        }
    }

    b[id][0] = mx1;
    b[id][1] = mx2;
}
int query(int l, int r) {
    int mx1 = 0, mx2 = 0;

    while (l <= r && l % BLOCK_SIZE != 0) {
        if (a[l] > mx1) {
            mx2 = mx1;
            mx1 = a[l];
        } else if (a[l] > mx2) {
            mx2 = a[l];
        }
        l++;
    }
    while (l + BLOCK_SIZE - 1 <= r) {
        int id = l / BLOCK_SIZE;
        if (b[id][0] > mx1) {
            mx2 = max(mx1, b[id][1]);
            mx1 = b[id][0];
        } else if (b[id][0] > mx2) {
            mx2 = b[id][0];
        } else if (b[id][1] > mx2) {
            mx2 = b[id][1];
        }
        l += BLOCK_SIZE;
    }
    while (l <= r) {
        if (a[l] > mx1) {
            mx2 = mx1;
            mx1 = a[l];
        } else if (a[l] > mx2) {
            mx2 = a[l];
        }
        l++;
    }

    return mx1 + mx2;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i += BLOCK_SIZE) update(i, a[i]);

    int q; cin >> q;
    while (q--) {
        char type; int a, b; cin >> type >> a >> b;
        if (type == 'U') update(a - 1, b);
        else cout << query(a - 1, b - 1) << "\n";
    }

    return 0;
}
// https://codeforces.com/problemset/problem/339/D
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

const int MAX_N = 1 << 17;
const int BLOCK_SIZE = 1 << 9;
const int N_BLOCKS = 1 << 8;

int n, block_size;
int a[MAX_N];
int aux[BLOCK_SIZE];
int blocks[N_BLOCKS];

void update(int i, int x) {
    a[i] = x;

    int block_id = i / BLOCK_SIZE,
        start = block_id * BLOCK_SIZE,
        end = min(start + BLOCK_SIZE, 1 << n);

    copy(a + start, a + end, aux);
    int r = end - start - 1, turn = 0;
    while (r) {
        int k = 0;
        for (int j = 0; j <= r; j += 2)
        if (!turn) aux[k++] = aux[j] | aux[j + 1];
        else aux[k++] = aux[j] ^ aux[j + 1];

        k = 0; turn ^= 1;
        r >>= 1;
    }

    blocks[block_id] = aux[0];
}
int query() {
    int r = ((1 << n) - 1) / BLOCK_SIZE;
    copy(blocks, blocks + r + 1, aux);

    int turn = 1;
    while (r) {
        int k = 0;
        for (int j = 0; j <= r; j += 2)
        if (!turn) aux[k++] = aux[j] | aux[j + 1];
        else aux[k++] = aux[j] ^ aux[j + 1];

        k = 0; turn ^= 1;
        r >>= 1;
    }

    return aux[0];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> n >> q;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];

    for (int i = 0; i < (1 << n); i += BLOCK_SIZE)
        update(i, a[i]);

    while (q--) {
        int i, x; cin >> i >> x;
        update(i - 1, x);
        cout << query() << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> &v) { for (int &x : v) cout << x << " "; cout << "\n"; }

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    cin >> A[i];

    sort(A.begin(), A.end());
    vector<int> B(n);
    int a = 0, b = 0;
    for (int x = 1; x <= 2 * n; x++) {
        if (A[a] == x) {
            a++;
            continue;
        }

        B[b++] = x;
    }

    a = 0, b = 0;
    int mx = 0;
    while (a < n && b < n) {
        while (a < n && A[a] < B[b]) a++;

        if (a >= n) break;

        mx++;
        a++;
        b++;
    }

    int b_mx = 0;
    a = 0, b = 0;
    while (a < n && b < n) {
        while (b < n && A[a] > B[b]) b++;

        if (b >= n) break;

        b_mx++;
        a++;
        b++;
    }

    cout << (n - b_mx) << " " << mx << "\n";

    return 0;
}
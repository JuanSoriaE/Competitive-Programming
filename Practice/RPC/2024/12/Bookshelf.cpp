#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, H; cin >> n >> H;

    int l, w, h, min_book_w;
    long long min_w = 0;

    while (n--) {
        cin >> l >> w >> h;
        vector<int> v = {l, w, h};
        sort(v.begin(), v.end());

        if (v[2] <= H)
            min_book_w = min(v[1], v[0]);
        else if (v[1] <= H)
            min_book_w = min(v[2], v[0]);
        else if (v[0] <= H)
            min_book_w = min(v[2], v[1]);
        else {
            cout << "impossible\n";
            return 0;
        }

        min_w += min_book_w;
    }

    cout << min_w << "\n";
    
    return 0;
}
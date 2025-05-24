#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define SZ(x) (ll)(x.size())

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int cc, cm, cy, ck; cin >> cc >> cm >> cy >> ck;
    int vc, vm, vy, vk; cin >> vc >> vm >> vy >> vk;
    int h, w; cin >> h >> w;
    int black = 0;
    int ans = 0;
    string row;
    while (h--) {
        cin >> row;
        for (char &c : row) {
            if (c == 'K') { black++; continue; }
            if (c == 'W') continue;

            if (c == 'R') {
                ans += cm + cy;
                vm--; vy--;
            } else if (c == 'G') {
                ans += cc + cy;
                vc--; vy--;
            } else if (c == 'B') {
                ans += cc + cm;
                vc--; vm--;
            } else if (c == 'C') {
                ans += cc;
                vc--;
            } else if (c == 'M') {
                ans += cm;
                vm--;
            } else if (c == 'Y') {
                ans += cy;
                vy--;
            }
        }
    }

    int printable = min(vc, min(vm, vy));
    if (cc + cm + cy < ck) {
        int printed = min(black, printable);
        ans += (cc + cm + cy) * printed;
        black -= printed;
        vc -= printed; vm -= printed; vy -= printed;
    } else {
        int printed = min(black, vk);
        ans += ck * printed;
        black -= printed;
        vk -= printed;
    }

    printable = min(vc, min(vm, vy));
    ans += min(black, vk) * ck;
    black -= min(black, vk);
    ans += min(black, printable) * (cc + cm + cy);

    cout << ans << "\n";

    return 0;
}
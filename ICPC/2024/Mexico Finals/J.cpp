#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795

long double DEG_to_RAD(int deg) { return deg * PI / 180.0; }

int main() {
  int theta, n;
  cin >> theta >> n;
  vector<pair<int, long double>> a(n);
  int x, h;
  long double aux = tan(DEG_to_RAD(theta));
  for (int i = 0; i < n; i++) {
    cin >> x >> h;
    a[i] = { x, x + h / aux };
  }

  sort(a.begin(), a.end());

  int l = a[0].first;
  long double r = a[0].second, res = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].first <= r) {
      r = max(r, a[i].second);
      continue;
    }

    res += r - l;
    l = a[i].first; r = a[i].second;
  }

  res += r - l;
  cout << setprecision(25) << res << "\n";

  return 0;
}

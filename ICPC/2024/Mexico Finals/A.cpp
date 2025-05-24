#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int i = s.size() - 2;
  while (i >= 0 && s[i] < s[i + 1])
    i--;

  cout << (i + 1) << endl;
}
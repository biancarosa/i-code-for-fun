#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

#define _N 1000

//Not accepted
int main() {
  int n, eq;
  double total, media, costs[_N], ans;
  while (cin >> n, n!=0) {
    total = 0;
    for (int i = 0; i < n; ++i) {
      cin >> costs[i];
      total += costs[i];
    }
    media = total / n;

    int i = 0;
    eq = 0;
    ans = 0;
    while (eq != n) {
      cout << costs[i] << "  :: " << media << endl;
      if (costs[i] == media) {
        eq++;
      } else {
        if (costs[i] > media) {
          cout << costs[i] - media << endl;
          ans += costs[i] - media;
          costs[i] = media;
          eq++;
        } else {
          cout << media - costs[i] << endl;
          ans += media - costs[i];
          costs[i] = media;
          eq++;
        }
      }
      cout << ans << endl;
      i = ++i % n;
    }

    cout << fixed << setprecision(5) << ans << " "  << ans / 2 << endl;
  }
  return 0;
}

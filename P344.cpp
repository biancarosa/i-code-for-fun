#include <iostream>
using namespace std;
//Not accepted yet
struct roman {
  int i = 0;
  int v = 0;
  int x = 0;
  int l = 0;
  int c = 0;
} roman;

struct roman arr[101];

struct roman toRoman(int n, struct roman r) {
  if (n < 10) {
    if (n < 4) {
      r.i += n;
    } else {
      if (n < 9) {
        r.i += abs(5-n);
        r.v += 1;
      } else {
        if ((10-n) == 1) {
          r.x++;
        }
        r.i += abs(10-n);
      }
    }
  } else {
    int x = n/10;
    r.x+=x;
    return toRoman(n-(10*x),r);
  }
  cout << "i :: " << r.i << " v :: " << r.v << " x :: " << r.x << " l :: " << r.l << " c :: " << r.c << endl;
  return r;
}

int main() {
  for (int i = 10; i <= 20; ++i) {
    struct roman r;
    r = toRoman(i, r);
    arr[i] = r;
  }
  return 0;
}

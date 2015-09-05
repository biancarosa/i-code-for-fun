#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct proposal {
  string name;
  double price;
  int met;
};


int main() {
  int n, p, r;
  string s, name;
  double d, total;
  struct proposal selected;
  int tc;

  tc = 0;
  while (cin >> n >> p) {
    if (n == 0 && p == 0) break;
    selected.met = -1;
    //cout << n << " " << p << endl;
    getline(cin,s);
    for (int i = 0; i < n; ++i) {
      getline(cin,s);
  //    cout << s << endl;
    }
    for (int i = 0; i < p; ++i) {
      getline(cin,name);
    //  cout << name << endl;
      cin >> d >> r;
    //  cout << d << "  " << r << endl;
      getline(cin,s);
      for (int j = 0; j < r; ++j) {
        getline(cin,s);
      //  cout << s << endl;
      }
      if (r > selected.met) {
        selected.met = r;
        selected.name = name;
        selected.price = d;
      } else {
        if (r == selected.met && d < selected.price) {
            selected.met = r;
            selected.name = name;
            selected.price = d;
        }
      }
    }

    if (tc != 0) cout << endl;
    cout << "RFP #" << ++tc << endl;
    cout << selected.name << endl;
  }

  return 0;
}

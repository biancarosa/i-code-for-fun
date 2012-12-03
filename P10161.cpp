#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int m, n, x, y, passos;
    while (cin >> n) {
        if (n == 0) break;
        m = (int)sqrt(n);
        passos = n - (m*m);
        if ((m*m) % 2 == 0) {
           if (passos != 0) {
                if (passos <= m+1) {
                    x = m+1;
                    y = passos;
                } else {
                    x = m+1;
                    passos-=m+1;
                    x-= passos;
                    y = m+1;
                }
            } else {
                x = m;
                y = 1;
            }
        } else {
            if (passos != 0) {
                if (passos <= m+1) {
                    x = passos;
                    y = m+1;
                } else {
                    x = m+1;
                    y = m+1;
                    passos-=m+1;
                    y-= passos;
                }
            } else {
                x = 1;
                y = m;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
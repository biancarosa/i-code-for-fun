#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, b, h, w, p, a;
	while (cin >> n >> b >> h >> w) {
		int minCost = 10001*201;
		while (h--) {
			cin >> p;
			for (int i = 0; i < w; ++i) {
				cin >> a;
				if (a >= n) {
					minCost = min(n*p,minCost);
				}
			}
		}
		if (minCost <= b) {
			cout << minCost << endl;
		} else {
			cout << "stay home" << endl;
		}
	}
	return 0;
}

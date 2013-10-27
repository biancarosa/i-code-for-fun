#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	int a, b, c;
	for (int i = 1; i <= t; ++i) {
		cin >> a >> b >> c;
		cout << "Case " << i << ": " << (a+b+c)-(max(max(a,b),c))-(min(min(a,b),c)) << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct _point {
	int x;
	int y;
};

string position(_point p,_point div) {
	if (p.x == div.x || p.y == div.y) {
		 return "divisa";
	} else {
		string ret;
		if (p.y > div.y) { ret = "N"; } else { ret = "S"; }
		if (p.x < div.x) { ret+= "O"; } else { ret+= "E"; }
		return ret;
	}
}

int main() {
	_point div;
	_point resid;
	int k;
	
	while (cin >> k >> div.x >> div.y) {
		while (k--) {
			cin >> resid.x >> resid.y;
			cout << position(resid, div) << endl;
		}
	}
	return 0;
}

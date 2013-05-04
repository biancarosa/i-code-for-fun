#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

struct Fraction {
    int n;
	int d;
};

vector<Fraction> farey; 

int mdc(int a, int b) {
    return b == 0 ? a : mdc( b, a % b );
}

bool comp(Fraction a, Fraction b) {
    return a.n*b.d < b.n*a.d;
}

int generateFarey(int fn) {
	Fraction f;
    f.n = fn;
    if (fn > 1) {
        generateFarey(fn-1);
    }
    for (int d = 1; d <= n; ++d) {
        if (mdc(fn, d) == 1) {
            f.d = d;
            farey.push_back(f);
        }
    }
    return 0;
}

int main() {
	while(cin >> n >> k) {
        farey.clear();
    	generateFarey(n);
        sort(farey.begin(),farey.end(),comp);
        cout << farey[k-1].n  << "/" << farey[k-1].d << endl;
	}
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

#define _N 25

int start[_N];
int final[_N];


int main() {
	int n, overtakes;
	while(cin >> n) {
		overtakes = 0;
		for (int i = 0; i < n; ++i) {
			cin >> start[i];
		}
		
		for (int i = 0; i < n; ++i) {
			cin >> final[i];
		}
		
		for (int i = 0; i <= n; ++i) {
			for (int j = n-1; j > i; --j) {
				if (start[j] == final[i]) {
					swap(start[j], start[j-1]);
                    overtakes++;
				}
			}	
		}
		
		cout << overtakes << endl;
	}
}

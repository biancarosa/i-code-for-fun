#include <iostream>

using namespace std;

//http://www.homeschoolmath.net/teaching/rational-numbers-countable.php
int main(){
	int n, diagonal, i, numerador, denominador;
    while (cin >> n) {
    	diagonal = 1;
    	for (i = n; i > diagonal; diagonal++) {
    		i -= diagonal;
    	}

    	//diagonais impares sobem, diagonais pares descem
    	numerador = i;
    	if (diagonal % 2) {
    		numerador = 1 + diagonal - numerador;
    	}

    	//a soma do numerador + denominador eh sempre diagonal + 1
    	denominador = diagonal + 1 - numerador;

        cout << "TERM " << n << " IS " << numerador << "/" << denominador << endl;
    }
}
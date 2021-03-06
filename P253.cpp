#include <iostream>

using namespace std;

char secondCube[6];
char firstCube[6];

int rotacionaX(){
    char c;
    c = secondCube[1];
    secondCube[1] =  secondCube[3];
    secondCube[3] =  secondCube[4];
    secondCube[4] =  secondCube[2];
    secondCube[2] =  c;
    return 0;
}

int rotacionaY(){
    char c;
    c = secondCube[1];
    secondCube[1] =  secondCube[0];
    secondCube[0] =  secondCube[4];
    secondCube[4] =  secondCube[5];
    secondCube[5] =  c;
    return 0;
}

int rotacionaZ(){
    char c;
    c = secondCube[0];
    secondCube[0] =  secondCube[3];
    secondCube[3] =  secondCube[5];
    secondCube[5] =  secondCube[2];
    secondCube[2] =  c;
    return 0;
}

bool testa() {
    for (int i = 0; i < 6; ++i) {
        if (firstCube[i] != secondCube[i]) 
            return false;
    }
    return true;
}

int main() {
    char c;
    bool canBePainted = false;
    int counter = 0;
    while (cin >> c) {
        if (counter < 6) {
            firstCube[counter] = c;        
        } else {
            secondCube[counter-6] = c; 
        }
        counter++;
        if (counter == 12) {
            for (int i = 0; i < 4; ++i) {
                rotacionaX();
                testa();
                for (int j = 0; j < 4; ++j) {
                    rotacionaY();
                    for (int k = 0; k < 4; ++k) {
                        rotacionaZ();
                        if (testa()) {
                            canBePainted = true;
                        }
                   }
               }
            }
            cout << (canBePainted?"TRUE":"FALSE") << endl; 
            canBePainted = false;
            counter = 0;
        }
    }
    return 0;
}
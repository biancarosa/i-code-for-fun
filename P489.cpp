#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

#define _N 1000

int main() {
  int r;
  string word, guess;
  int arr[_N];
  int arrW[_N];
  int right = 0;
  int wrong = 0;
  bool anyRight = false;
  int c;
  while (cin >> r, r != -1) {
    cin >> word;
    cin >> guess;
    memset (arr, 0, sizeof(arr));
    memset (arrW, 0, sizeof(arrW));
    right = 0;
    wrong = 0;
    for (int i = 0; i < guess.size(); ++i) {
      anyRight = false;
      for (int j = 0; j < word.size(); ++j) {
        if (guess[i] == word[j]) {
          if (arr[j] == 0) {
            arr[j] = 1;
            right++;
          }
          anyRight = true;
        }
      }
      if (!anyRight) {
        cout << word[i] << endl;
        c = word[i];
        cout << c << endl;
        if (arrW[c] == 0) {
          arrW[c] = 1;
          wrong++;
        }
      }
      if (wrong >= 7 && right < word.size()) break;
    }
    cout << right << " " << wrong << endl;
    cout << "Round " << r << endl;
    if (right >= word.size()) {
      cout << "You win." << endl;
    } else  if (wrong >= 7) {
      cout << "You lose." << endl;
    } else {
      cout << "You chickened out." << endl;
    }
  }
}

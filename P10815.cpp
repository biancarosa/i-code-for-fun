#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;
 
list<string> splitWords(string word) {
    list<string> splittedWords;
    string w = "";
    for (int i = 0; i < word.size(); ++i) {
        if (isalpha(word.at(i))) {
            w+=tolower(word.at(i));
        } else {
            if (!w.empty())
            splittedWords.push_back(w);
            w = "";
        }        
    }
    if (!w.empty()) splittedWords.push_back(w);
    return splittedWords;
}

int main() {
    int n;
    string s;
    list<string> aux;
    map<string,int> words;
    cin >> n;
    while (cin >> s) {
        if (s == "EndOfText") break;
        aux = splitWords(s);
        for (list<string>::iterator it = aux.begin(); it != aux.end(); ++it) {
            words[*it]++;
        }
    }
    bool has = false;
    for (map<string,int>::iterator it=words.begin(); it!=words.end(); ++it) {
        if (it->second == n) {
            has = true;
            cout << it->first << endl;
        }
    }
    if (!has) cout << "There is no such word." << endl;
    return 0;
}

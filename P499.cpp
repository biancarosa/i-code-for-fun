#include <iostream>
#include <map>
#include <ctype.h>
using namespace std;

int main (){
   
   map<char,int> mapa;
   map<char,int>::iterator it;
   string::iterator it1;
   string s;
   int highFreq;


   while  (getline(cin,s)) {
      highFreq = 0;
      //Usando um iterator p/ percorrer a string
      for (it1=s.begin(); it1 < s.end(); ++it1 ) {
         //Se for alpha, aumentamos o mapped value do mapa.
         if(isalpha(*it1)) { 
   	    mapa[*it1]++; 
   	    if (mapa[*it1] > highFreq) highFreq = mapa[*it1];
   	 }
      }
      //Maps em C++ s�o automaticamente ordenados pela chave. 
      //Imprimimos as chaves que possuem mapped value = maior frequ�ncia guardada
      for (it=mapa.begin(); it != mapa.end(); ++it )
         if ((*it).second == highFreq) cout << (*it).first;
      cout << " " << highFreq << endl;
      
      mapa.clear();
   }
   return 0;
}
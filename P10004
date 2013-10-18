#include <iostream>
#include <string.h>
using namespace std;
 
#define _N 205
 
int graph[_N][_N];
int color[_N];
int n;
 
//Basic DFS algorithm with some changes
//Graph is bicolorable if it can be dividided into two partitions (bipartite)
bool isBicolorable(int v = 0, int colorToPaint = 1) {
  	color[v] = colorToPaint;
    int nextColor = colorToPaint == 1 ? 2 : 1;
 
    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
                if (!color[i]) {
                  //trying to color next vertice with the next color
                	if (!isBicolorable(i, nextColor)) {
                		return false;
                	}
                } else if (color[i] == colorToPaint) {
                  //its already colored with an impossible color
                	return false;
                }
        }
    }
 
    return true;
}
 
int main() {
   int l, u, v;
   while (cin >> n) {
      if (n == 0) break;
      cin >> l;
      for (int i = 0; i < n; i++) memset(graph[i], 0, n*sizeof(int));
      memset(color, 0, n*sizeof(int));
 
      for (int i = 0; i < l; ++i) {
         cin >> u >> v;
         graph[u][v] = 1;
         graph[v][u] = 1; 
      }
 
      if (isBicolorable()) {
         cout << "BICOLORABLE." << endl;
      }  else {
         cout << "NOT BICOLORABLE." << endl;    
      }
   }
   return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//Not accepted yet

#define EPS 1e-9
#define PI acos(-1.0)

struct point_i {
  int x, y;
  point_i() { x = y = 0.0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
} point_i;

struct point_i p;
vector<struct point_i> P1;
vector<struct point_i> P2;
int n;

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };


  double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

  double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

vec toVec(struct point_i a, struct point_i b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }



double angle(struct point_i a, struct point_i o, struct point_i b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(struct point_i p, struct point_i q, struct point_i r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }


  // returns true if point p is in either convex/concave polygon P
  bool inPolygon(struct point_i pt, const vector<struct point_i> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;    // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
      if (ccw(pt, P[i], P[i+1]))
           sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
      else sum -= angle(P[i], pt, P[i+1]); }                 // right turn/cw
    return fabs(fabs(sum) - 2*PI) < EPS; }

int main() {
  while (cin >> n) {
    cout << n << endl;
    P2.clear();
    P1.clear();
    for (int i = 0; i < n; ++i) {
      cin >> p.x >> p.y;
      P1.push_back(p);
    }
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      cin >> p.x >> p.y;
      P2.push_back(p);
    }

    for (int i = 0; i < (int)P2.size(); ++i) {
      cout << P2[i].x << " " << P2[i].y << " " << inPolygon(P2[i] , P1) << endl;
    }


    for (int i = 0; i < (int)P1.size(); ++i) {
      cout << P1[i].x << " " << P1[i].y << " " << inPolygon(P1[i] , P2) << endl;
    }

    cout << " eee" << endl;
  }
  return 0;
}

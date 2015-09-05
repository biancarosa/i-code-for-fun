#include <iostream>
#include <string>

using namespace std;

// +y
string moveTop(string pointedAt) {
  if (pointedAt == "+x") pointedAt = "+y";
  else if(pointedAt == "-x") pointedAt = "-y";
  else if (pointedAt == "+y")  pointedAt = "-x";
  else if (pointedAt == "-y" )   pointedAt = "+x";
  else if (pointedAt == "+z")  pointedAt = "+z";
  else if (pointedAt == "-z")  pointedAt = "-z";
  return pointedAt;
}

//-y
string moveDown(string pointedAt) {
  if (pointedAt == "+x") pointedAt = "-y";
  else if(pointedAt == "-x") pointedAt = "+y";
  else if (pointedAt == "+y")  pointedAt = "+x";
  else if (pointedAt == "-y" )   pointedAt = "-x";
  else if (pointedAt == "+z")  pointedAt = "+z";
  else if (pointedAt == "-z")  pointedAt = "-z";
  return pointedAt;
}

//+z
string moveFront(string pointedAt) {
  if (pointedAt == "+x") pointedAt = "+z";
  else if(pointedAt == "-x") pointedAt = "-z";
  else if (pointedAt == "+y")  pointedAt = "+y";
  else if (pointedAt == "-y" )   pointedAt = "-y";
  else if (pointedAt == "+z")  pointedAt = "-x";
  else if (pointedAt == "-z")  pointedAt = "+x";
  return pointedAt;
}

//-z
string moveBack(string pointedAt) {
  if (pointedAt == "+x") pointedAt = "-z";
  else if(pointedAt == "-x") pointedAt = "+z";
  else if (pointedAt == "+y")  pointedAt = "+y";
  else if (pointedAt == "-y" )   pointedAt = "-y";
  else if (pointedAt == "+z")  pointedAt = "+x";
  else if (pointedAt == "-z")  pointedAt = "-x";
  return pointedAt;
}


int main() {
  int l;
  string s, to;
  string pointedAt;
  while (cin >> l, l != 0) {
    pointedAt = "+x";
    for (int i = 0; i < l-1; ++i) {
      cin >> to;
      if (to == "+y") pointedAt = moveTop(pointedAt);
      else if (to == "-y") pointedAt = moveDown(pointedAt);
      else if (to == "+z") pointedAt = moveFront(pointedAt);
      else if (to == "-z")  pointedAt = moveBack(pointedAt);
    }
    cout << pointedAt << endl;
  }
  return 0;
}

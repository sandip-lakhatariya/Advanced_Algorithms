#include <bits/stdc++.h>
using namespace std;

struct points {
   int x;
   int y;
};

int direction (points pi, points pj, points pk){
   int xi = pk.x - pi.x;
   int xj = pj.x - pi.x;
   int yi = pk.y - pi.y;
   int yj = pj.y - pi.y;


   int mul = (xi * yj) - (yi * xj);
   return mul;
}

bool onSegment (points pi, points pj, points pk) {
   if(min(pi.x, pj.x) <= pk.x <= max(pi.x, pj.x) && min(pi.y, pj.y) <= pk.y <= max(pi.y, pj.y))
       return true;
   return false;
}

bool segment_intersect (points pi, points pj, points pk, points pl){
   int d1 = direction(pk, pl, pi);
   int d2 = direction(pk, pl, pj);
   int d3 = direction(pi, pj, pk);
   int d4 = direction(pi, pj, pl);

   if(d1*d2 < 0 && d3*d4 < 0){
       return true;
   }
   else if(d1 == 0 && onSegment(pk, pl, pi)){
       return true;
   }
   else if(d2 == 0 && onSegment(pk, pl, pj)){
       return true;
   }
   else if(d3 == 0 && onSegment(pi, pj, pk)){
       return true;
   }
   else if(d4 == 0 && onSegment(pi, pj, pl)){
       return true;
   }
   else{
       return false;
   }
}

int main() {
   struct points p1, p2, p3, p4;
   cout << "Enter 4 points value in (x, y) form : " << endl;;
   cin >> p1.x >> p1.y;
   cin >> p2.x >> p2.y;
   cin >> p3.x >> p3.y;
   cin >> p4.x >> p4.y;

   cout << "Points are intersect : " << segment_intersect(p1, p2, p3, p4);
   return 0;
}

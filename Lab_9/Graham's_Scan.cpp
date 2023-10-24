#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

struct points {
    int x;
    int y;
    double angle;
};

points nextToTop(stack<points> &st){
    points p = st.top();
    st.pop();
    points res = st.top();
    st.push(p);
    return res;
}

int direction (points pi, points pj, points pk){
   int xi = pk.x - pi.x;
   int xj = pj.x - pi.x;
   int yi = pk.y - pi.y;
   int yj = pj.y - pi.y;


   int mul = (xi * yj) - (yi * xj);
   return mul;
}

bool comparator(points const& lhs, points const& rhs) {
    return lhs.angle < rhs.angle;
}

void GS(struct points pts[], int n) {

    struct points p0 = pts[0];
    for(int i = 1; i < n; i++){
        if(pts[i].y < p0.y){
            p0 = pts[i];
        }
        else if(pts[i].y == p0.y){
            pts[i].x < p0.x ? p0 = pts[i] : p0 = p0;
        }
    }

    for(int i = 0; i < n; i++){
        pts[i].angle = atan2(double(pts[i].y-p0.y), double(pts[i].x-p0.x)) * 180 / PI;
    }

    sort(pts, pts+n, &comparator);

    stack<points> st;
    st.push(pts[0]);
    st.push(pts[1]);
    st.push(pts[2]);

    for(int i = 3; i < n; i++){
        while(direction(nextToTop(st), st.top(), pts[i]) >= 0){
            st.pop();
        }
        st.push(pts[i]);
    }

    cout << "Convex hull pionts is : " << endl;
    while(!st.empty()){
        cout << st.top().x << " " << st.top().y << endl;
        st.pop();
    }

}
z
int main() {

    int n = 7;

    struct points pts[7] = {{0, 0}, {3, 1}, {4, 4}, {1, 2}, {0, 5}, {2, 2}, {-1, 3}};

    GS(pts, n);

    return 0;
}

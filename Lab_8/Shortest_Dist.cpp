#include <bits/stdc++.h>
using namespace std;

vector<int> Closest_pt(vector<vector<int>> P){
    float min = INT16_MAX;
    int n = P.size();
    vector<int> ans(2);

    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            float d = sqrt(pow((P[i][0]-P[j][0]), 2) + pow((P[i][1]-P[j][1]), 2));
            if(d < min){
                min = d;
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}

int main() {

    vector<vector<int>> P = {{2, 2}, {4, 4}, {5, 6}};

    vector<int> ans = Closest_pt(P);

    cout << ans[0] + 1 << " " << ans[1] + 1 << endl;

    return 0;
}

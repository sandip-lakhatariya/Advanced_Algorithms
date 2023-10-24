#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

int main() {
    // string t = "jimy hailed the leader to stop";
    // string p = "leader";

    // string t = "this is an apple";
    // string p = "apple";

    string t = "jim saw me in a barber shop";
    string p = "barber";

    // string t = "aaaaaaaaaaaaa";
    // string p = "aaa";

    int n = t.length();
    int m = p.length();
    vector<int> shift(26, m);

    for(int i = 0; i < m - 1; i++){
        int j = p[i] - 'a';
        shift[j] = m - 1 - i;
    }

    int j = 0; 
    while(j + m <= n){
        if(++cnt && t[j+m-1] == p[m-1]){
            int i = m - 2;
            while(i >= 0 && ++cnt && p[i] == t[j+i]){
                i--;
            }
            if(i == -1){
                cout <<  "Pattern found at index : " << j << endl;
            }
        }
        if(t[j+m-1] == ' '){
            j += m;
        }
        else{
            j = j + shift[t[j+m-1] - 'a'];
        }
    }
    cout << "Number of comperision : " << cnt << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int cmp = 0;

bool compare(string t, string p, int s, int m){
    for(int i = s; i < s + m; i++){
        cmp++;
        if(t[i] != p[i-s]){
            return false;
        }
    }
    return true;
}

int main(){

    string t = "This is an apple, apple is a red";
    string p = "apple";

    int n = t.length();
    int m = p.length();

    for (int s = 0; s <= n - m; s++)
    {
        if(compare(t, p, s, m)){
            cout << "Pattern Found at index: " << s << endl;
        }
    }
    cout << "Total comparision : " << cmp << endl;
    
    return 0;
}

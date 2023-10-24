#include <bits/stdc++.h>
using namespace std;

bool check_suffix(string P, int k, int q, int j){
    if(k == 0){
        return true;
    }
    if(j == 0 && P[k-1] == 'a'){
        for(int i = k-2; i > -1; i--){
            if(P[i] != P[q-1]) return false;
            q--;
        }
        return true;
    } 
    else if(j == 1 && P[k-1] == 'b'){
        for(int i = k-2; i > -1; i--){
            if(P[i] != P[q-1]) return false;
            q--;
        }
        return true;
    }
    return false;
}

void FA_string_matching(string T, string P){

    int n = T.length();
    int m = P.length();
    int x = 2; // size of |E|
    int d[m+1][2];

    // creating FA
    for(int q = 0; q <= m; q++){
        for(int j = 0; j < x; j++){
            int k = min(m + 1, q + 2);
            do{
                k--;
            }while (!check_suffix(P, k, q, j));
            d[q][j] = k;
        }
    }

    // Print Delta Table
    
    // for(int i = 0; i <= m; i++){
    //     for(int j = 0; j < 2; j++) {
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int q = 0;
    for(int i = 0; i < n; i++){
        q = d[q][T[i]-'a'];
        if(q == m){
            cout << "Pattern Found at shift : " << i - m + 1 << endl;
        }
    }

}

int main() {
    string T = "abaababbababaaab";
    string P = "ababa";
    // string T = "ababaaab";
    // string P = "baaa";
    FA_string_matching(T, P);

    return 0;
}

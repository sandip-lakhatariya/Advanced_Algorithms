#include <bits/stdc++.h>
using namespace std;

bool check(string text, string pattern, int s, int m) {
    for(int i = s; i < s + m; i++){
        if(text[i] != pattern[i - s]){
            return false;
        }
    }
    return true;
}

void rabin_karp(string text, string pattern, int d, int q) {

    int p = 0, t = 0;
    int m = pattern.length(), n = text.length();

    for(int i = 0; i < m; i++){
        p = ((d * p) + pattern[i] - '0');
        t = ((d * t) + text[i] - '0');
    }

    p %= q;
    t %= q; 
    
    int h = pow(d, m-1);
    h %= q;

    for(int s = 0; s <= n-m; s++) {
        if(p == t){ //  expected # of spurious hits = O(n/q)
            if(check(text, pattern, s, m)){
                cout << "Pattern find at shift : " << s << endl;
            }
        }
        t = ((t - (text[s] - '0') * h) * d + (text[s + m] - '0')) % q;
        while(t < 0){
            t += q;
        }
    }

}

int main() {
    string text = "32134244784754244487359837465983470275897289789738752897424478971845767648578380244244";
    string pattern = "424478";
    int q = 11;
    int d = 10;
    rabin_karp(text, pattern, d, q);
    return 0;
}

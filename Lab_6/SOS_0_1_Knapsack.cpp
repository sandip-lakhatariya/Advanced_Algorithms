#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    bool knapSack(int W, int P, int wt[], int val[], int n) { 
        int arr[n+1][W+1];
        for(int i = 0; i <= n; i++){
            arr[i][0] = 0;
        }
        for(int i = 0; i <= W; i++){
            arr[0][i] = 0;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++){
                if(j < wt[i-1]){
                    arr[i][j] = arr[i-1][j];
                }
                else{
                    arr[i][j] = max(arr[i-1][j], val[i-1] + arr[i-1][j - wt[i-1]]);
                }
            }
        }
        if(arr[n][W] >= P){
            return true;
        }
        else{
            return false;
        } 
    }

    bool SOS(int s[], int sum, int n) {
        int W = sum;
        int P = sum; 
        int wt[n], val[n];

        for(int i = 0; i < n; i++){
            wt[i] = s[i];
            val[i] = s[i];
        }

        return knapSack(W, P, wt, val, n);
    }
};

int main()
 {
    // int n = 6;
    // int s[n] = {4, 3, 6, 8, 5, 9}; 
    // int sum = 23;

    int n = 5;
    int s[n] = {3, 5, 7, 9, 11};
    int sum = 13;

    Solution ob;

    if(ob.SOS(s, sum, n))
        cout << "Sum is possible" << endl;
    else
        cout << "Sum is not possible" << endl;

	return 0;
}

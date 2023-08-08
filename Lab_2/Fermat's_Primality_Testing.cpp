#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(ll a, ll b){
	if(a < b)
        return gcd(b, a);
    else if(a % b == 0)
        return b;
    else
        return gcd(b, (a % b));
}

int power (ll a, unsigned int n, ll p){
	int res = 1;
	a = a % p;
	
	while(n > 0){
		if(n & 1){
			res = (res * a) % p;
		}
		n = n >> 1;
		a = (a * a) % p;
	}		
	return res;
}

bool isPrime(unsigned ll n){
	if(n == 1 || n == 4){
		return false;
	}
	if(n == 2 || n == 3){
		return true;
	}
	
	int k = 100;
	
	while(k > 0){
	
		int a = 2 + rand() % (n - 4);
		
		if(gcd(n,a) != 1){
			return false;
		}
		if(power(a, n-1, n) != 1){
			return false;
		}
		k--;
	}
	return true;
}

int main(){
	unsigned ll num;
	cin >> num;	
	cout << "Number is Prime : " << isPrime(num);
	return 0;
};



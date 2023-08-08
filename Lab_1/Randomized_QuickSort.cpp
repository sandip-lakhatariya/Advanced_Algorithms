#include <bits/stdc++.h>
using namespace std;
int comp = 0;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[], int l, int h) {
	int x = arr[h];
	int i = l - 1;
	for(int j = l; j <= h - 1; j++){
		if(++comp && arr[j] <= x){ // count the number of comparisons
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[h]);
	return i + 1;
}

int randomized_partition(int arr[], int l, int h){
	srand(time(NULL));
	int i;
	i = l + rand()%(h-l+1);
	swap(arr[i], arr[h]);
	return(partition(arr, l, h));
}

void randomized_Quick_sort(int arr[], int l, int h) {
	if(l < h) {
		int q = randomized_partition(arr, l, h);
		randomized_Quick_sort(arr, l, q-1);
		randomized_Quick_sort(arr, q+1, h);
	}
}

int main() {
	int n;
	cout << "The Value of n is : ";
	cin >> n;
	cout << "Enter " << n << " Elements : ";
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	randomized_Quick_sort(arr, 0, n-1);
	cout << "Sorted Elements : ";
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Number of Comparision : " << comp << endl;
	return 0;
}

/** 3 4 4 5 6 8 9 10 10 12 12 19 20 21 23 24 29 29 30 30 32 34 34 40 43 43 45 45 45 50 50 50 54 54 57 64 65 65 69 76 78 80 82 87 87 89 91 98 98 432 799 */

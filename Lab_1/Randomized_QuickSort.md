# Randomized QuickSort Algorithm

### Description:

* Although the ‘traditional’ Quicksort algorithm is very efficient in practice, 
its worst-case running time is relatively slow. When sorting n elements, the number 
of comparisons may be **O(N^2)**. The worst case happens if the sizes of the sub-problems 
are not balanced. 

* The selection of the pivot element determines the sizes 
of the subproblems. It is thus crucial to select a **‘good pivot’**.

* The randomized algorithm avoids the worst-case behavior by randomly choosing a pivot.

### Approach:

* Similarly to the general Quick Sort algorithm, it partitions the input array
A into two partitions and makes two recursive calls to sort them.

* The difference here is in the choice of the pivot. Instead of choosing a fixed pivot, 
The algorithm selects pivot **r** at random for the index range **p** to **q**.

### Complexity:

* Time Complexity: **O(NlogN)**
* Space Complexity: **No extra space is required.**

### Note:

* Randomized QuickSort algorithm is the **Las Vegas** type of algorithm as it always produces correct answers.

### code:

```
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
```

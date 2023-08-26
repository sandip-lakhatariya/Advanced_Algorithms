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
function test() {
  console.log("notice the blank line before this function?");
}
```

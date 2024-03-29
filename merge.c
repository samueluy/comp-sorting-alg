/* Quick sort in C
Taken from: https://www.programiz.com/dsa/merge-sort

*/

#include <stdio.h>

// Merge two subarrays L and M into arr
unsigned long merge(int arr[], int p, int q, int r) {
	unsigned long counter_value=0;
  // Create L ? A[p..q] and M ? A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

	int i,j;
  for (i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (j = 0; j < n2; j++){
  	M[j] = arr[q + 1 + j];
	counter_value++;
  }

  // Maintain current index of sub-arrays and main array
  int k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
  	counter_value++;
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
  	counter_value++;
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
  	counter_value++;
    arr[k] = M[j];
    j++;
    k++;
  }
  return counter_value;
}

// Divide the array into two subarrays, sort them and merge them
unsigned long merge_sort_driver(int arr[], long l, long r) {
	unsigned long counter_value=0;
	counter_value++;
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    counter_value += merge_sort_driver(arr, l, m);
    counter_value += merge_sort_driver(arr, m + 1, r);

    // Merge the sorted subarrays
    counter_value += merge(arr, l, m, r);
  }
  return counter_value++;
}

unsigned long merge_sort(int arr[], long l, long r){
	unsigned long counter_value = merge_sort_driver(arr, l, r);
	return counter_value;
}



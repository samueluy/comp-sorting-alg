// https://www.programiz.com/dsa/selection-sort

#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int array[], int size) {
	int i, step;
	for (step = 0; step < size - 1; step++) {
    	int min_idx = step;
		for (i = step + 1; i < size; i++) {
			
      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      	if (array[i] < array[min_idx])
	        min_idx = i;
   		}
   		
    	// put min at the correct position
    	swap(&array[min_idx], &array[step]);
  	}
}

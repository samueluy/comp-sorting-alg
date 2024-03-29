// https://www.programiz.com/dsa/selection-sort

#include <stdio.h>

void swap(int *a, int *b, unsigned long *counter_value) {
	counter_value++;
  int temp = *a;
  *a = *b;
  *b = temp;
}

unsigned long selection_sort(int array[], int size) {
	unsigned long counter_value;
	int i, step;
	for (step = 0; step < size - 1; step++) {
    	int min_idx = step;
		for (i = step + 1; i < size; i++) {
			counter_value++;
			
      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      	if (array[i] < array[min_idx])
	        min_idx = i;
   		}
   		
    	// put min at the correct position
    	swap(&array[min_idx], &array[step], &counter_value);
  	}
  	return counter_value;
}

// https://www.programiz.com/dsa/insertion-sort

#include <stdio.h>

void insertion_sort(int array[], int size) {
	int step=1;
	for(step = 1; step < size; step++) {
	   int key = array[step];
	   int j = step - 1;
	    // Compare key with each element on the left of it until an element smaller than
	   // it is found.
	   // For descending order, change key<array[j] to key>array[j].
	   while (key < array[j] && j >= 0) {
	     array[j + 1] = array[j];
	     --j;
	   }
	   array[j + 1] = key;
	 }
}

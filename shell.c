/* Shell Sort in C programming
Taken from : https://www.programiz.com/dsa/shell-sort

*/
#include <stdio.h>

// Shell sort
unsigned long shell_sort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  int i,j, interval;
  unsigned long counter_value;
  for (interval = n / 2; interval > 0; interval /= 2)
 	{
    	for (i = interval; i < n; i += 1) {
	      int temp = array[i];
	    for (j = i; j >= interval && array[j - interval] > temp; j -= interval){
	    	array[j] = array[j - interval];
	    	counter_value++;
		}
    	
      array[j] = temp;
    }
  }
  return counter_value;
}




/* Quick sort in C
Taken from: https://hackr.io/blog/quick-sort-in-c
*/

#include<stdio.h>
unsigned long quick_sort(int array[],int first,int last)
{
	unsigned long counter_value = 0;
	counter_value++;
	int i, j, pivot, temp;
	if(first<last)	
	{
	// find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
		pivot = first;
		i = first;
		j = last;
		while(i<j)
		{
			while(array[i]<=array[pivot]&&i<last)
				i++;
			while(array[j]>array[pivot])
				j--;
			if(i<j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		temp = array[pivot];
		array[pivot]=array[j];
		array[j]=temp;
		
		//	Recursive call on the left and right side of the array.
		counter_value+=quick_sort(array,first,j-1);
		counter_value+=quick_sort(array,j+1,last);
	}
	return counter_value;
}






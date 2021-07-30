#define CPU_TIME  (1)
#define MAX_SIZE 10000000

#include <stdio.h>
#include <time.h>

// Files
#include "bubble.c"
#include "insertion.c"
#include "selection.c"
#include "Merge Sort.c"
#include "Shell Sort.c"
#include "Quick Sort.c"
#include "GenerateArray.c"


int bubbleMeasureMET(int array[], int size){
    // Start measuring time
    struct timespec begin, end; 
	
	#if CPU_TIME
	
	    // get start CPU time
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
	
	    /* Call sorting function */
		bubble_sort(array, size);
	    
	    // Stop measuring time and calculate the elapsed time
	#if CPU_TIME 
	
	    // get end CPU time
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	
	   clock_gettime(CLOCK_REALTIME, &end);
	
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
	    
	    //printf("CPU Time measured: %lf in seconds.\n", elapsed);
	    printf("CPU Time measured: %.4lf in miliseconds.\n", elapsed*1000);
	    
	    return elapsed*1000;
	}
    
int insertionMeasureMET(int array[], int size){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		insertion_sort(array, size);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %.4lf in miliseconds.\n", elapsed*1000);    
	    return elapsed*1000;
}

int selectionMeasureMET(int array[], int size){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		selection_sort(array, size);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %.4lf in miliseconds.\n", elapsed*1000);    
	    return elapsed*1000;
}

int mergeMeasureMET(int array[], long size){
    struct timespec begin, end; 
	
///	size = sizeof(array) / sizeof(array[0]);
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		mergeSort(array, 0, size - 1);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %lf in miliseconds.\n", elapsed*1000);    
	    return elapsed*1000;
}

int shellMeasureMET(int array[], int size){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		shellSort(array, size);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %lf in miliseconds.\n", elapsed*1000);    
	    return elapsed*1000;
}

int quickMeasureMET(int array[], long size){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    	
		quickSort(array, 0, size - 1);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %lf in miliseconds.\n", elapsed*1000);    
	    return elapsed*1000;
}


	
int exponent(int base, int power){ // get value when raised to a power
	int result=1;
    	while(power != 0){
    		result *= base;
    		power--;
		}
	return result;
}

void arrayCopy(int source[], int target[], int size){
	int i;
	for(i=0; i<size; i++){
		target[i] = source[i];
	}
}

int main () {
	srand(time(NULL)); // set random seed for randomization
	
	int static N1[MAX_SIZE], N2[MAX_SIZE], N3[MAX_SIZE];
    int i, y, nSize;
    double bubble_time, insertion_time, selection_time, merge_time, shell_time, quick_time;
    bubble_time = insertion_time = selection_time = merge_time =  shell_time =  quick_time = 0;

    for(i=0; i<6; i++){ // 6 different sizes of arrays
    	nSize = exponent(2, i+12); // set size of array
    	printf("Current array size: %d\n\n", nSize);
    	for(y=0; y<10; y++){
    		printf("Test#%d/10\n", y+1);
    		
    		// Generate arrays
    		GenerateData(N1, nSize); // Generate base array
    		arrayCopy(N1, N2, nSize);
    		arrayCopy(N1, N3, nSize);
    		
    		// Print results
    		printf("Bubble: ");
    		bubble_time += bubbleMeasureMET(N1, nSize);
    		printf("Insertion: ");
    		insertion_time += insertionMeasureMET(N2, nSize);
    		printf("Selection: ");
    		selection_time += selectionMeasureMET(N3, nSize);
    		printf("Merge: ");
    		merge_time += mergeMeasureMET(N3, nSize);
    		printf("Shell: ");
    		shell_time += shellMeasureMET(N3, nSize);
    		printf("Quick: ");
    		quick_time += quickMeasureMET(N3, nSize);
    		printf("\n");
		}
		printf("----------------------------------------------------------\n");
		printf("Bubble Sort = Average time: %lf miliseconds\n", bubble_time/10);
		printf("Insertion Sort = Average time: %lf miliseconds\n", insertion_time/10);
		printf("Selection Sort = Average time: %lf miliseconds\n", selection_time/10);
		printf("Merge Sort = Average time: %lf miliseconds\n", merge_time/10);
		printf("Shell Sort = Average time: %lf miliseconds\n", shell_time/10);
		printf("Quick Sort = Average time: %lf miliseconds\n", quick_time/10);
		printf("----------------------------------------------------------\n");
		bubble_time=0;
		insertion_time=0;
		selection_time=0;
		merge_time=0;
		shell_time=0;
		quick_time=0;
    	printf("\nEND\n\n");
	}
    
    
    return 0;
}

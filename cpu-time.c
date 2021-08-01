#define CPU_TIME  (1)
#define MAX_SIZE 10000000

#include <stdio.h>
#include <time.h>

// Files
#include "bubble.c"
#include "insertion.c"
#include "selection.c"
#include "merge.c"
#include "shell.c"
#include "quick.c"
#include "GenerateArray.c"


int bubbleMeasureMET(int array[], int size, unsigned long *counter_value){
    // Start measuring time
    struct timespec begin, end; 
	
	#if CPU_TIME
	
	    // get start CPU time
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
	
	    /* Call sorting function */
		*counter_value = bubble_sort(array, size);
	    
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
	    printf("CPU Time measured: %.4lf in miliseconds.\t\t\t Counter: %lu\n", elapsed*1000, *counter_value);
	    
	    return elapsed*1000;
	}
    
int insertionMeasureMET(int array[], int size, unsigned long *counter_value){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		*counter_value = insertion_sort(array, size);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %.4lf in miliseconds.\t\t\t Counter: %lu\n", elapsed*1000, *counter_value);    
	    return elapsed*1000;
}

int selectionMeasureMET(int array[], int size, unsigned long *counter_value){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		*counter_value = selection_sort(array, size);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %.4lf in miliseconds.\t\t\t Counter: %lu\n", elapsed*1000, *counter_value);    
	    return elapsed*1000;
}

int mergeMeasureMET(int array[], long size, unsigned long *counter_value){
    struct timespec begin, end; 
///	size = sizeof(array) / sizeof(array[0]);
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		*counter_value = merge_sort(array, 0, size - 1);
		

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %.4lf in miliseconds.\t\t\t Counter: %lu \n", elapsed*1000, *counter_value);    
	    return elapsed*1000;
}

int shellMeasureMET(int array[], int size, unsigned long *counter_value){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
		*counter_value = shell_sort(array, size);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %.4lf in miliseconds.\t\t\t Counter: %lu\n", elapsed*1000, *counter_value);    
	    return elapsed*1000;
}

int quickMeasureMET(int array[], long size, unsigned long *counter_value){
    struct timespec begin, end; 
	
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    	
		*counter_value = quick_sort(array, 0, size - 1);

	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	   
	#endif
		long seconds = end.tv_sec - begin.tv_sec;
	    long nanoseconds = end.tv_nsec - begin.tv_nsec;
		double elapsed = seconds + nanoseconds*1e-9;
		
	    printf("CPU Time measured: %.4lf in miliseconds.\t\t\t Counter: %lu\n", elapsed*1000, *counter_value);    
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
	
	int static N1[MAX_SIZE], N2[MAX_SIZE], N3[MAX_SIZE], N4[MAX_SIZE], N5[MAX_SIZE], N6[MAX_SIZE];
    int i, y, nSize;
    double bubble_time, insertion_time, selection_time, merge_time, shell_time, quick_time;
    bubble_time = insertion_time = selection_time = merge_time =  shell_time =  quick_time = 0;
    unsigned long bubble_counter, insertion_counter, selection_counter, merge_counter, shell_counter, quick_counter;
	bubble_counter = insertion_counter =  selection_counter = merge_counter =  shell_counter = quick_counter = 0;
	unsigned long bubble_counter_ave, insertion_counter_ave, selection_counter_ave, merge_counter_ave, shell_counter_ave, quick_counter_ave;
	bubble_counter_ave = insertion_counter_ave =  selection_counter_ave = merge_counter_ave =  shell_counter_ave = quick_counter_ave = 0;

    for(i=0; i<6; i++){ // 6 different sizes of arrays
    	nSize = exponent(2, i+12); // set size of array
    	printf("Current array size: %d\n\n", nSize);
    	for(y=0; y<10; y++){
    		printf("Test#%d/10\n", y+1);
    		
    		// Generate arrays
    		GenerateData(N1, nSize); // Generate base array
    		arrayCopy(N1, N2, nSize);
    		arrayCopy(N1, N3, nSize);
    		arrayCopy(N1, N4, nSize);
    		arrayCopy(N1, N5, nSize);
    		arrayCopy(N1, N6, nSize);
    		
    		// Print results
    		printf("Bubble: ");
    		bubble_time += bubbleMeasureMET(N1, nSize, &bubble_counter);
    		bubble_counter_ave += bubble_counter;
    		printf("Insertion: ");
    		insertion_time += insertionMeasureMET(N2, nSize, &insertion_counter);
    		insertion_counter_ave += insertion_counter;
    		printf("Selection: ");
    		selection_time += selectionMeasureMET(N3, nSize, &selection_counter);
    		selection_counter_ave += selection_counter;
    		printf("Merge: ");
    		merge_time += mergeMeasureMET(N4, nSize, &merge_counter);
    		merge_counter_ave += merge_counter;
    		printf("Shell: ");
    		shell_time += shellMeasureMET(N5, nSize, &shell_counter);
    		shell_counter_ave += shell_counter;
    		printf("Quick: ");
    		quick_time += quickMeasureMET(N6, nSize, &quick_counter);
    		quick_counter_ave += quick_counter;
    		printf("\n");
		}
		printf("----------------------------------------------------------\n");
		printf("Bubble Sort = Average time: %.4lf miliseconds\n", bubble_time/10);
		printf("Insertion Sort = Average time: %.4lf miliseconds\n", insertion_time/10);
		printf("Selection Sort = Average time: %.4lf miliseconds\n", selection_time/10);
		printf("Merge Sort = Average time: %.4lf miliseconds\n", merge_time/10);
		printf("Shell Sort = Average time: %.4lf miliseconds\n", shell_time/10);
		printf("Quick Sort = Average time: %.4lf miliseconds\n", quick_time/10);
		printf("----------------------------------------------------------\n");
		printf("Bubble Sort = Average counter: %.4lu\n", bubble_counter_ave/10);
		printf("Insertion Sort = Average counter: %.4lu\n", insertion_counter_ave/10);
		printf("Selection Sort = Average counter: %.4lu\n", selection_counter_ave/10);
		printf("Merge Sort = Average counter: %.4lu\n", merge_counter_ave/10);
		printf("Shell Sort = Average counter: %.4lu\n", shell_counter_ave/10);
		printf("Quick Sort = Average counter: %.4lu\n", quick_counter_ave/10);
		bubble_time=0;
		insertion_time=0;
		selection_time=0;
		merge_time=0;
		shell_time=0;
		quick_time=0;
		bubble_counter_ave=0;
		insertion_counter_ave=0;
		selection_counter_ave=0;
		merge_counter_ave=0;
		shell_counter_ave=0;
		quick_counter_ave=0;
    	printf("\nEND\n\n");
	}
    
    
    return 0;
}

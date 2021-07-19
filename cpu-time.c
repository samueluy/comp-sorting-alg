#define CPU_TIME  (1)

#include <stdio.h>
#include <time.h>

// Files
#include "bubble.c"
#include "insertion.c"
#include "selection.c"
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
	    printf("CPU Time measured: %lf in miliseconds.\n", elapsed*1000);
	    
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
		
	    printf("CPU Time measured: %lf in miliseconds.\n", elapsed*1000);    
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
	
	int N1[100000], N2[100000], N3[100000];
    int i, y, nSize;
    double bubble_time, insertion_time, selection_time;

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
    		printf("\n");
		}
		printf("----------------------------------------------------------\n");
		printf("Bubble = Average time: %lf miliseconds\n", bubble_time/10);
		printf("Insertion = Average time: %lf miliseconds\n", insertion_time/10);
		printf("Selection = Average time: %lf miliseconds\n", selection_time/10);
		printf("----------------------------------------------------------\n");
		bubble_time=0;
		insertion_time=0;
		selection_time=0;
    	printf("\nEND\n\n");
	}
    
    
    return 0;
}

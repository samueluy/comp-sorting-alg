#define CPU_TIME  (1)

#include <stdio.h>
#include <time.h>

// Files
#include "bubble.c"
#include "GenerateArray.c"


int main () {
	
	srand(time(NULL)); // set random seed for randomization
	
	int N[100000];
    int i, y, nSize;
    double time;

int measureMET(int array[], int size){
    // Start measuring time
    struct timespec begin, end; 
	
	#if CPU_TIME
	
	    // get start CPU time
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	
	#else
	
	    clock_gettime(CLOCK_REALTIME, &begin);
	
	#endif    
	
	    /* Call sorting function */
		bubble_sort(N, nSize);
	    
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
    
int exponent(int base, int power){ // get value when raised to a power
	int result=1;
    	while(power != 0){
    		result *= base;
    		power--;
		}
	return result;
}

    for(i=0; i<6; i++){ // 6 different sizes of arrays
    	nSize = exponent(2, i+10); // set size of array
    	printf("Current array size: %d\n", nSize);
    	for(y=0; y<10; y++){
    		GenerateData(N, nSize);
    		time += measureMET(N, nSize);
		}
		printf("Average time: %lf miliseconds", time/10);
		time=0;
    	printf("\nEND\n\n");
	}
    
    
    return 0;
}

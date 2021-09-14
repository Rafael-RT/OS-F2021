#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void){
	// For every calls forks() function, it creates 1 child processe
	// So in every iteration number of processes will increased in 2 times
	// In result when we have loop with 3 iteration, we create 8 processes
	// for 5 iteration - 32 processes
	for(int i = 0; i < 3; i++){
		fork();
		sleep(5);
	}
	
	return 0;
}

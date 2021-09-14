#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv){

	int num;
	sscanf(argv[1], "%d", &num);
	int pid = fork();
	
	if(pid > 0){
		printf("Hello from a parent [%d-%d]\n", pid, num);
	} else if(pid == 0){
		printf("Hello from a child [%d-%d]\n", pid, num);
	} else {
		return -1;
	}
	return 0;
}

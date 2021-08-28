#include <stdio.h>

int main(int argc, char **argv){
	
	int num;
	sscanf(argv[1], "%d", &num);
	
	for(int i = 0; i < num; i++){
		int j;
		
		for(j = 0; j < num-1-i; j++) putchar(' ');
		for(j = 0; j < i*2+1; j++) putchar('*');
		
		putchar('\n');	
		
	}
	
	return 0;
}


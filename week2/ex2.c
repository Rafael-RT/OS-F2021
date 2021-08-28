#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	
	char str[256];
	printf("Enter the string\n");
	
	scanf("%s", str);
	
	for(int i = strlen(str) - 1; i >= 0; i--){
		putchar(str[i]);
	}
	
	printf("\n");
	return 0;
}



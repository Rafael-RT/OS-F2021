#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char **argv){
	printf("Enter the first number:\n");
	
	int firstNum;
	scanf("%d", &firstNum);
	
	printf("Enter the second number:\n");
	
	int secondNum;
	scanf("%d", &secondNum);
	
	swap(&firstNum, &secondNum);
	
	printf("After swapping\nfirst number = %d second number = %d\n", firstNum, secondNum);
	
	return 0;
}



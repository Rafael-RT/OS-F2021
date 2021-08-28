#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv){
	
	int x = INT_MAX;
	float y = FLT_MAX;
	double z = DBL_MAX;
	
	printf("Integer max = %d\n", x);
	printf("Float max = %f\n", y);
	printf("Double max = %f\n", z);
	
	printf("Size of integer = %ld\n", sizeof(x));
	printf("Size of float = %ld\n", sizeof(y));
	printf("Size of double = %ld\n", sizeof(z));
	
	
	return 0;
}



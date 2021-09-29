#include <stdlib.h>
#include <stdio.h>

int* ownReal(int *oldArr, int size){
    
    if(oldArr == NULL){
        return malloc(size);
    }
    
    if(size == 0){
        free(oldArr);
        return NULL;
    }
    
    int *newArr = malloc(size);
    int n;
    
    if(sizeof(oldArr) > size){
        n = size;
    }
    else {
        n = sizeof(oldArr);
    }
    
    for(int i = 0; i < sizeof(oldArr); i++){
            *(newArr + i) = *(oldArr);
    }
    free(oldArr);
    return newArr;
}

int main(){
    printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = calloc(n1, sizeof(int));
	
	if(a1 == NULL){
	    printf("Allocating memory");
	    return 0;
	}
	
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		*(a1 + i) = 100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", *(a1 + i) );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = ownReal(a1, sizeof(int) * n2);

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
    if(n2 > n1){
        for(int i = n1; i < n2; i++){
            *(a1 + i) = 0;
        }
    }
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", *(a1 + i));
	}
	printf("\n");
	
	//Done with array now, done with program :D
	free(a1);
	return 0;
}

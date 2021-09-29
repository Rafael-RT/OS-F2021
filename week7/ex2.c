#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    printf("Enter a number n: ");
    scanf("%d", &n);
    
    int *arr = calloc(n, sizeof(int));
    
    for(int i = 0; i < n; i++){
        *(arr + i) = i;
        
        printf("arr[%d] = %d\n", i, *(arr + i));
        
    }
    
    free(arr);
    
}

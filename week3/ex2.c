#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* arr, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(){
	printf("Enter the size of an array:\n");
	int n;
	scanf("%d", &n);
	
	printf("Enter the element of an array:\n");
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	bubble_sort(arr, n);
	
	printf("Sorted array:\n");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	putchar('\n');
	
	return 0;
	
}

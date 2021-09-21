#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void* myThread(void* arg){
    printf("     -> Hello from thread:%i!\n", * (int*)arg);
    pthread_exit(NULL);
}

int main()
{
    int n;
    printf("Enter a number N:\n");
    scanf("%d", &n);
    pthread_t thread;
    
    for(int i = 1; i <= n; i++){
        printf("Creating Thread #%d ...\n", i);
        if(pthread_create(&thread, NULL, myThread, &i)){
            printf(" >>ERROR IN CREATING Thread #%d!\n", i);
            pthread_exit(NULL);
            return 1;
        } else{
            printf ("   >>Thread #%d created!\n",i);
        }
        pthread_join(thread, NULL);
    }

    return 0;
}




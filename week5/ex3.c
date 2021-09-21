#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define EMPTY  0
#define BUFFER_SIZE 5
int buff[BUFFER_SIZE];
int elemIndex=0;
int producerLock=1;
int consumerLock=0;
void* producer(void *arg){
    while(1){
        while(producerLock){
            if (elemIndex == BUFFER_SIZE){
                producerLock=0;
                consumerLock=1;
                printf("BUFFER IS FULL!\n");
                continue;
            }
        buff[elemIndex] = elemIndex + 1000;
        printf(">> PRODUCER: New data produced in the buffer[INDEX #%d: %d]\n",elemIndex,buff[elemIndex]);
        elemIndex++;
        }
    }
    pthread_exit(NULL);
    return 0;
    }
void* consumer(void *arg){
    while(1){
        while(consumerLock){
            if (elemIndex==0){
                producerLock=1;
                consumerLock=0;
                printf("NO DATA TO CONSUME!\n");
                continue;
            }
            int data =buff[--elemIndex];
            buff[elemIndex]=EMPTY;
            printf(">> CONSUMER: Produced data consumed from the buffer[INDEX #%d: EMPTY]\n",elemIndex);
        }
    }
    pthread_exit(NULL);
    return 0;

}
int main(){
    pthread_t consumer_t;
    pthread_t producer_t;
    pthread_create(&producer_t,NULL,producer,NULL);
    pthread_create(&consumer_t,NULL,consumer,NULL);
    pthread_join(consumer_t,NULL);
    pthread_join(producer_t,NULL);
    pthread_exit(NULL);
    return 0;
}

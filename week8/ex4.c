#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>


int main()
{
    struct rusage usage;
    int second = 0;
    while(second < 10) {
        int* block=(int*)malloc(10485760);
        memset(block, 0, sizeof(block));
        getrusage(RUSAGE_SELF, &usage);
        printf("Used memory in KB: %ld \n", usage.ru_maxrss);
        sleep (1);
        second++;
    }
    return 0;
}

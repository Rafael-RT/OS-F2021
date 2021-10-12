#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
    int second = 0;
    while(second < 10) {
        int* block=(int*)malloc(10485760);
        memset(block, 0, sizeof(block));
        sleep (1);
        second++;
    }
    // with command vmstat 1, si and so fields will be 0
    // with command top we can see how our memory allocates
    return 0;
}

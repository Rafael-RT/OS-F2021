
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct frame
{
    unsigned int page;
    unsigned int age;
    unsigned int R;
} frame_t;

int findPage(int page, frame_t frames[], int numFrames)
{
    for(int i=0; i<numFrames; i++)
        if(frames[i].page == page)
            return i;
    return -1;
}

void updateAge(frame_t frames[], int numFrames)
{
    for(int i=0; i<numFrames; i++)
    {
        // The counters are shifted right 1 bit.
        frames[i].age = frames[i].age >> 1;
        // The R-bit is added to the leftmost bit.
        frames[i].age |= frames[i].R << 30;
        // Nullify all R-bits.
        frames[i].R = 0;
    }
}

int indexLeastCounter(frame_t frames[], int numFrames)
{
    int leastAge = INT_MAX;
    int leastIndex = 0;
    for(int i=0; i<numFrames; i++)
    {
        if(frames[i].age < leastAge)
        {
            leastAge = frames[i].age;
            leastIndex = i;
        }
    }
    return leastIndex;
}

int main()
{
    int numFrames, numHits=0, numMisses=0, cTick=0, interval=1;

    printf("Specify number of frames: ");
    scanf("%d", &numFrames);
    printf("Specify clock interval: ");
    scanf("%d", &interval);

    frame_t frames[numFrames];
    for(int i=0; i<numFrames; i++)
    {
        frames[i].age = 0;
        frames[i].page = -1;
        frames[i].R = 0;
    }

    FILE *pageReferences = fopen("Lab_09_input.txt", "r");
    while(!feof(pageReferences))
    {
        int page;
        fscanf(pageReferences, "%d", &page);
        int idPage = findPage(page, frames, numFrames);
        if(idPage != -1)
        {
            numHits++;
            frames[idPage].R = 1;
        }
        else
        {
            numMisses++;
            int toReplace = indexLeastCounter(frames, numFrames);
            frames[toReplace].page = page;
            frames[toReplace].age = 1 << 30;
            frames[toReplace].R = 1;
        }
        if(cTick % interval == 0)
            updateAge(frames, numFrames);
        cTick++;
    }
    
    float ratio = (float)numHits/numMisses;
    printf("Hits number: %d.\nMisses number: %d.\nHit/Miss ratio: %f.\n", numHits, numMisses, ratio);
    return 0;
}

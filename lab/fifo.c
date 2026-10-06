#include <stdio.h>

int main(){
    int pages[50],frames[10];
    int n,f,i,j;
    int pageFaults = 0, pageHits = 0, front = 0;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter page numbers: ");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);
    printf("Enter number of frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
        frames[i] = -1;
    printf("FIFO Page Replacement:\n");
    printf("Page\tFrames\tStatus\n");
    for(i=0;i<n;i++){
        int found = 0;
        for(j=0; j<f; j++){
            if(frames[j] == pages[i]){
                found = 1;
                break;
            }
        }
        if(found)
            pageHits++;
        else{
            pageFaults++;
            frames[front] = pages[i];
            front = (front + 1) % f;       
        }
        printf("%d\t", pages[i]);
        for(j=0; j<f; j++){
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        if(found)
            printf("\tHit\n");
        else
            printf("\tFault\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
}
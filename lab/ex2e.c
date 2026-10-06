#include <stdio.h>
#include <unistd.h>

int main(){
    void *curr_brk, *new_brk;
    curr_brk = sbrk(0);
    printf("Current break: %p\n", curr_brk);
    sbrk(1024);
    printf("After sbrk(1024): %p\n", sbrk(0));
    new_brk = sbrk(0);
    if(brk(new_brk+2048) == 0){
        printf("brk(+2048) : %p\n", sbrk(0));
    } else {
        printf("brk() failed\n");
    }
    if(brk(curr_brk) == 0){
        printf("brk(curr_brk) : %p\n", sbrk(0));
    } else {
        printf("brk() failed\n");
    }
    return 0;
}
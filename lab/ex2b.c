#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Before exec()\n");
    execl("/bin/ls", "ls", "-l", NULL);
    printf("After exec()");
    return 0;
}
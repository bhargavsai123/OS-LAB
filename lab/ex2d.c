#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    printf("User ID: %d\n", getuid());
    printf("Group ID: %d\n", getgid());
    printf("Effective User ID: %d\n", geteuid());
    printf("Effective Group ID: %d\n", getegid());
    return 0;
}
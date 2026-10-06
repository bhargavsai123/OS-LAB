#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t child_pid = fork();
    if(child_pid < 0){
        printf("Forlk failed\n");
        return 1;
    }
    else if(child_pid == 0){
        printf("Child Process created successfully\n");
        printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
    }
    else{
        wait(NULL);
        printf("Parent Process created successfully\n");
        printf("Parent Process: PID = %d, PPID = %d\n", getpid(), getppid());
    }
}
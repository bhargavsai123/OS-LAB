#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main(){
	int shmid;
	pid_t pid;
	char* shared_memory;
	char message[] = "Hello from Parent Process!";
	// Create Shared Memory Segment
	shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
	if(shmid == -1){
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared Memory created sucessfully.\n");
	// Create Child Process
	pid = fork();
	if(pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid > 0){
		// Parent Process
		shared_memory = (char *)shmat(shmid,NULL,0);
		if(shared_memory == (char *)-1){
			perror("shmat");
			exit(EXIT_FAILURE);
		}
		printf("Parent Process : Writing message to Shared Memory...\n");
		strcpy(shared_memory,message);
		printf("Parent Process : Message written sucessfully.\n");
		// Detact Shared Memory
		shmdt(shared_memory);
		// Wait for Child
		wait(NULL);
		// Remove Shared Memory
		if(shmctl(shmid,IPC_RMID,NULL) == -1){
			perror("shmctl");
			exit(EXIT_FAILURE);
		}
		printf("Parent Process : Shared Memory removed.\n");
	}
	else {
		// Child Process
		sleep(1);
		shared_memory = (char*)shmat(shmid,NULL,0);
		if(shared_memory == (char*)-1){
			perror("shmat");
			exit(EXIT_FAILURE);
		}
		printf("Child Process : Reading Message from Shared Memory...\n");
		printf("Child Process : Message Received : %s\n",shared_memory);
		// Detact Shared Memory
		shmdt(shared_memory);
	}
	return 0;
}

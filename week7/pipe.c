#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int pipefd[2];
	pid_t pid;

	char write_message[] = "Hello from Parent Process!";
	char read_message[100];

	// Create Pipe
	if(pipe(pipefd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// Create Child Process
	pid = fork();
	if(pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if(pid > 0){
		// Parent Process
		printf("Parent Process : Sending message to Child...\n");
		close(pipefd[0]); // Parent does not read from Child
		write(pipefd[1], write_message, strlen(write_message) + 1); // Write Message to pipe
		printf("Parent Process : Message sent sucessfully.\n");
		close(pipefd[1]); //Close Write end
		wait(NULL); // Wait for Child process to finish
		printf("Parent Process : Child process completed.\n");
	}
	else{
		// Child Process
		close(pipefd[1]); // Child does not write to pipe
		read(pipefd[0], read_message, sizeof(read_message)); // Read Message from pipe
		printf("Child Process : Message Received : %s\n",read_message);
		close(pipefd[0]);
		exit(0);
	}
	return 0;
}

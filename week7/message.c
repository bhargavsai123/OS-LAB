#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct message{
	long message_type;
	char message_text[100];
};

int main(){
	int msgid;
	pid_t pid;
	struct message msg;

	msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
	if(msgid == -1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	printf("Message Queue created sucessfully.\n");

	// Child Process
	pid = fork();
	if(pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid > 0){
		// Parent Process
		msg.message_type = 1;
		strcpy(msg.message_text, "Hello from Parent Process!");
		printf("Parent Process : Sending Message...\n");
		if(msgsnd(msgid, &msg, sizeof(msg.message_text),0) == -1){
			perror("msgsnd");
			exit(EXIT_FAILURE);
		}
		printf("Parent Process : Message sent sucessfully.\n");
		// Wait for Child
		wait(NULL);
		// Remove Message Queue
		if(msgctl(msgid,IPC_RMID,NULL) == -1){
			perror("msgctl");
			exit(EXIT_FAILURE);
		}
		printf("Parent Process : Message Queue Removed.\n");
	}
	else{
		// Child Process
		sleep(1);
		printf("Child Process : Waiting for Message...\n");
		if(msgrcv(msgid,&msg,sizeof(msg.message_text),1,0) == -1){
			perror("msgrcv");
			exit(EXIT_FAILURE);
		}
		printf("Child Process : Message Received : %s\n",msg.message_text);
	}
	return 0;
}

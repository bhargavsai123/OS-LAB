#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Current PID : %d\n",getpid());
	int p = nice(5);
	printf("New nice value : %d\n",p);
	printf("Sleeping for 5 seconds...\n");
	sleep(5);
	printf("Program Resumed.\n");
	return 0;
	
}

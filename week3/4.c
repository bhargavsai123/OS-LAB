#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Before exec()\n");
	execl("/bin/ls","ls","-l",NULL);
	printf("This Line will not execute if exec is sucessful.");
	return 0;
}

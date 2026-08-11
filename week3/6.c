#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Process ID : %d\n",getpid());
	printf("User ID : %d\n",getuid());
	printf("Effective User Id : %d\n",geteuid());
	return 0;
}

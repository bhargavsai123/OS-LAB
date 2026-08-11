#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd1,fd2;
	int number;
	fd1 = open("kk.txt", O_RDONLY | O_CREAT, 0644);
	fd2 = open("kk1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 == -1 || fd2 == -1){
		printf("Error opening files\n");
		return 1;
	}
	printf("File Descriptor of kk.txt = %d\n",fd1);
	printf("File Descriptor of kk1.txt = %d\n",fd2);
	printf("\nCurrent Process ID (PID) = %d\n",getpid());
	printf("\nOpen another terminal and execute the following commands:\n");
	printf("----------------------------------------------------------\n");
	printf("ls /proc/%d\n",getpid());
	printf("cat /proc/%d/status\n",getpid());
	printf("cat /proc/%d/maps\n",getpid());
	printf("ls -l /proc/%d/fd\n",getpid());
	printf("\nPress any integer after observing the /proc directory : ");
	scanf("%d", &number);
	close(fd1);
	close(fd2);
	return 0;

}

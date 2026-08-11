#include <stdio.h>
#include <fcntl.h>
int main(){
	int fd = open("f7.txt",O_RDONLY);
	printf("File Opened\nFile Descriptor : %d\n",fd);
	return 0;
}

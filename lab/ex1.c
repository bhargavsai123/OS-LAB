#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("file.txt", O_RDWR | O_CREAT, 0644);
    char buffer[100];
    if(fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    printf("Enter text to write to file: \n");
    scanf("%s", buffer);
    write(fd, buffer, sizeof(buffer));
    lseek(fd,0,SEEK_SET);
    read(fd,buffer,sizeof(buffer));
    printf("Content of file: %s\n", buffer);
    close(fd);
    return 0;
}
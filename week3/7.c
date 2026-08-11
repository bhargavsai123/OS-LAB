#include <stdio.h>
#include <unistd.h>

int main(){
	void *current_break, *new_break;
	current_break = sbrk(0);
	printf("Initial Program Break : %p\n",current_break);
	sbrk(1024);
	printf("After sbrk(1024) : %p\n",sbrk(0));
	new_break = sbrk(0);
	if(brk(new_break+2048) == 0){
		printf("After brk(+2048) : %p\n",sbrk(0));
	}
	else{
		perror("brk failed");
	}
	if(brk(current_break) == 0){
		printf("After restoring break : %p\n",sbrk(0));
	}
	else{
		perror("brk restore failed");
	}
	return 0;
}

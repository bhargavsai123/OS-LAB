#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg){
	printf("Thread is Executing.\n");
	for(int i = 1; i <= 5; i++)
		printf("Thread : %d\n",i);
	printf("Thread has Completed.\n");
	return NULL;
}

int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread_function,NULL);
	pthread_create(&t2,NULL,thread_function,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Both Threads have completed.\n");
	return 0;
}

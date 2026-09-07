#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg){
	int number = *(int*)arg;
	printf("Thread %d is executing\n",number);
	for(int i = 1; i <= 5; i++)
		printf("Thread %d : %d\n",number,i);
	printf("Thread %d has completed\n",number);
	return NULL;
}

int main(){
	pthread_t t1,t2;
	int n1 = 1, n2 = 2;
	pthread_create(&t1,NULL,thread_function,&n1);
	pthread_create(&t2,NULL,thread_function,&n2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Both threads have completed.\n");
	return 0;
}

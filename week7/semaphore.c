#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int shared = 1;
sem_t semaphore;

// Thread1 function
void *function1(void *arg){
	int x;
	sem_wait(&semaphore);
	x = shared;
	printf("Thread 1 : Reads shared value as : %d\n",x);
	x++;
	printf("Thread 1 : Updates local value as : %d\n",x);
	sleep(1);
	shared = x;
	printf("Thread 1 : Updates shared value as : %d\n",shared);
	sem_post(&semaphore);
	return NULL;
}
// Thread2 function
void *function2(void *arg){
	int y;
	sem_wait(&semaphore);
	y = shared;
	printf("Thread 2 : Reads shared value as : %d\n",y);
	y--;
	printf("Thread 2 : Updates local value as : %d\n",y);
	sleep(1);
	shared = y;
	printf("Thread 2 : Updates shared value as : %d\n",shared);
	sem_post(&semaphore);
	return NULL;
}

int main(){
	pthread_t t1, t2;
	// Semaphore Initialization
	if(sem_init(&semaphore,0,1) != 0){
		perror("sem_init");
		exit(EXIT_FAILURE);
	}
	// Create Two Threads
	if(pthread_create(&t1,NULL,function1,NULL) != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}	
	if(pthread_create(&t2,NULL,function2,NULL) != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	// Wait for both threads
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Final Value of Shared Variable = %d\n",shared);
	sem_destroy(&semaphore);
	return 0;
}

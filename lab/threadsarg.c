#include<stdio.h>
#include<pthread.h>

void*tf(void *arg){
    int num = *(int*)arg;
    printf("Thread is executing\n");
    printf("Value passed: %d\n", num);
    printf("Thread is completed\n");
    return NULL;
}

int main(){
    pthread_t t1,t2;
    int arg1 = 10;
    int arg2 = 20;
    pthread_create(&t1,NULL,tf,&arg1);
    pthread_create(&t2,NULL,tf,&arg2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Both threads are completed\n");
    return 0;
}
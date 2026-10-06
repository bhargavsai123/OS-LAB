#include<stdio.h>
#include<pthread.h>

void *tf(void *arg){
    printf("Thread is executing\n");
    for(int i=1;i<=10;i++){
        printf("Thread: %d\n",i);
    }   
    printf("Thread is completed\n");
    return NULL;
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,tf,NULL);
    pthread_create(&t2,NULL,tf,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Both threads are completed\n");
    return 0;
}
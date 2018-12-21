#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

void THread1(void *arg){   // 线程1函数
    sleep(1);
    int i,j;
    int policy;
    int num = (int)arg;    // 传入参数
    struct sched_param param; // pthread_self()  线程ID获取函数。
    pthread_getschedparam(pthread_self(), &policy, &param);
    if(policy == SCHED_RR)
        printf("SCHED_RR \n");
    for(i=1; i<num; i++){
        for(j=0; j<500000; j++){  // 执行循环，效果类似sleep(), 不会让出cpu
        }
        printf("THread 1: %d\n", param.sched_priority);
    }
    printf("Thread 1 exit\n");
}
void THread2(void *arg){
    sleep(1);
    int i,j;
    int policy;
    int num = (int)arg;
    struct sched_param param;
    pthread_getschedparam(pthread_self(), &policy, &param);
    if(policy == SCHED_RR)
        printf("SCHED_RR \n");
    for(i=1; i<num; i++){
        for(j=0; j<500000; j++){
        }
        printf("THread 2: %d\n", param.sched_priority);
    }
    printf("Thread 2 exit\n");
}
void THread3(void *arg){
    sleep(1);
    int i,j;
    int policy;
    int num = (int)arg;
    struct sched_param param;
    pthread_getschedparam(pthread_self(), &policy, &param);
    if(policy == SCHED_RR)
        printf("SCHED_RR \n");
    for(i=1; i<num; i++){
        for(j=0; j<500000; j++){
        }
        printf("THread 3: %d\n", param.sched_priority);
    }
    printf("Thread 3 exit\n");
}

void THread4(void *arg){
    sleep(1);
    int i,j;
    int policy;
    int num = (int)arg;
    struct sched_param param;
    pthread_getschedparam(pthread_self(), &policy, &param);
    if(policy == SCHED_RR)
        printf("SCHED_RR \n");
    for(i=1; i<num; i++){
        for(j=0; j<500000; j++){
        }
        printf("THread 4: %d\n", param.sched_priority);
    }
    printf("Thread 4 exit\n");
}
void THread5(void *arg){
    sleep(1);
    int i,j;
    int policy;
    int num = (int)arg;
    struct sched_param param;
    pthread_getschedparam(pthread_self(), &policy, &param);
    if(policy == SCHED_RR)
        printf("SCHED_RR \n");
    for(i=1; i<num; i++){
        for(j=0; j<500000; j++){
        }
        printf("THread 5: %d\n", param.sched_priority);
    }
    printf("Thread 5 exit\n");
}
int main(){
    pthread_t tid[5];
    struct sched_param param[5];
    
    pthread_attr_t attr[5];
    pthread_attr_init(&attr[0]);

    for(int i=1; i<5; i++){
        pthread_attr_init(&attr[i]);
        param[i].sched_priority = i*10 + 10;
        pthread_attr_setschedpolicy(&attr[i], SCHED_RR);
        pthread_attr_setschedparam(&attr[i], &param[i]);
        pthread_attr_setinheritsched(&attr[i], PTHREAD_EXPLICIT_SCHED);

    }
    
int count = 5;
    pthread_create(&tid[0], &attr[0], (void*)THread5, (void*)count);
    pthread_create(&tid[1], &attr[1], (void*)THread4, (void*)count);
    pthread_create(&tid[2], &attr[2], (void*)THread3, (void*)count);
    pthread_create(&tid[3], &attr[3], (void*)THread2, (void*)count);
    pthread_create(&tid[4], &attr[4], (void*)THread1, (void*)count);

    pthread_join(tid[4], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[0], NULL);

    pthread_attr_destroy(&attr[4]);
    pthread_attr_destroy(&attr[3]);
    pthread_attr_destroy(&attr[2]);
    pthread_attr_destroy(&attr[1]);
    pthread_attr_destroy(&attr[0]);
    return 0;
}


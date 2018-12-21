#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>

# define ARRAY_SIZE 1024
# define MALLOC_SIZE 1024
# define KEY 200
char array[ARRAY_SIZE];

int main(){

    int       shmid;
    char    *ptr, *shmptr;
    // 全局变量的地址
    printf("array addr: %p to %p \n", (void *)&array[0], (void *)&array[ARRAY_SIZE-1]);

    // 局部变量的地址（存放在栈中）
    printf("stach addr: %p \n", &shmid);

    // 堆地址， malloc从堆中申请地址
    if ((ptr = malloc(MALLOC_SIZE)) == NULL){
        printf("malloc error\n");
        exit(-1);
    }
    printf("malloc addr: %p to %p \n", (void*)&ptr, (void*)&ptr+MALLOC_SIZE);
    
    
// 共享内存地址
    if ((shmid = shmget(KEY, 1024, 0777 | IPC_CREAT | IPC_EXCL)) < 0)
    {
        printf("shmget error\n");
        exit(-1);
    }
    if ((shmptr = shmat(shmid, 0, 0))==(void*)-1){
        printf("shmat error\n");
        exit(-1);
    }
    printf("share memory addr: %p to %p\n", (void*)shmptr, (void*)shmptr+1024);

    if (shmctl(shmid, IPC_RMID, 0) < 0){
        printf("shmctl error\n");
        exit(-1);
    }
    return 0;
}



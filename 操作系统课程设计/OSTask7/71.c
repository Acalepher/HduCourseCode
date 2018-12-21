#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>

#define KEY 100

typedef struct message{
    pid_t pid;
    char buf[1024];
}msg;

int main()
{
    int shmid;
    msg *sChild, *sParent;
    pid_t p = fork();
    if (p == 0)
    {
        shmid = shmget(KEY, 1024, 0777 | IPC_CREAT | IPC_EXCL);
        if (shmid < 0)
        {
            printf("shmget error\n");
            exit(-1);
        }
          // 连接共享存储段
        sChild = shmat(shmid, NULL, 0);  
        // 写入数据
        sChild->pid = getpid();
        strcpy(sChild->buf, "hello world\n");
    }
    if (p > 0)
    {
        sleep(2);
        shmid = shmget(KEY, 1024, 0777);
        sParent = shmat(shmid, NULL, 0);
        printf("child pid is : %d\n", sParent->pid);
        printf("data is : %s\n", sParent->buf);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

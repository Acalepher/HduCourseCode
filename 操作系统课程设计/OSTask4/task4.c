#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid, wpid;

    pid = fork();

    if (pid == 0)  // 子进程
    {
        sleep(10); // 休眠10s
        exit(1);  // 子进程退出
    }
    
else if (pid > 0)  // 父进程
    {
        do
        {
            // 轮询方式探测是否是子进程pid 是否可以被回收，status暂时不考虑，我们使用NULL
            wpid = waitpid(pid, NULL, WNOHANG);  
            if (wpid == 0)  // 子进程不可回收
            {
                printf("no child exit\n");
                sleep(1);
            }
            if (wpid == pid) // 子进程被回收
                printf("success wait child\n");
        }while(wpid == 0);

        printf("parent exit\n");
    }
    return 0;
}

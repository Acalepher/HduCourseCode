#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);
    if (ret == -1)
    {
        perror("error\n");
        exit(1);
    }

    pid_t pid = fork();
    int red;
    if (pid == 0)   // 子进程
    {
        // sleep(10);
        close(fd[1]);
        char buf[1024];
        red = read(fd[0], buf, sizeof(buf));
        if (red == 0)
        {
            perror("read error\n");
            exit(1);
        }
        printf("%s\n\n", buf);
        write(STDOUT_FILENO, buf, ret);
    }
else   // 父进程
    {
        sleep(2);
        close(fd[0]);
        write(fd[1], "hello world\n", strlen("hello world\n"));
    }

    return 0;
}


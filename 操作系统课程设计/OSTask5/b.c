#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);
    int red;
    if (ret == -1)
    {
        perror("error\n");
        exit(1);
    }
pid_t pid = fork();
    
    if (pid == 0)
    {
        // sleep(10);
        close(fd[1]);
        char buf[1024];
        memset(buf, 0, 1024);
        red = read(fd[0], buf, sizeof(buf));
        if (red == 0)
        {
            perror("read error\n");
            exit(1);
        }
        write(STDOUT_FILENO, buf, red);
    }
else
    {
        sleep(2);
        close(fd[0]);
        char buf[1024];
        memset(buf, 0, 1024);
        ret = read(STDIN_FILENO, buf, sizeof(buf));
        //dup2(fd[1], STDIN_FILENO);
        write(fd[1], buf, strlen(buf));
        sleep(2);
    }
    

    return 0;
}

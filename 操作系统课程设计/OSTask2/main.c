//
//  main.c
//  OS Task2
//
//  Created by Acaleph ❦ on 2018/7/9.
//  Copyright © 2018年 Acaleph ❦. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    // 打开文件
    int fd;  // 文件描述符
    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC);
    // 使用或运算，将多个flags组合使用。
    // 注： 由于使用O_CREAT，每次运行前，需要删除已经建立的文件。否则报错
    if (fd == -1)
    {
        printf("open error\n");
        exit(-1);
    }
    // 向文件内写数据
    char buf[1024] = "this is a test";
    int ret = write(fd, buf, strlen(buf));
    if (ret == -1)
    {
        printf("write error\n");
        exit(-1);
    }
    // 从文件内读数据
    memset(buf, 0, sizeof(buf));
    ret = read(fd, buf, sizeof(buf));
    if (ret == -1)
    {
        printf("read error\n");
        exit(-1);
    }
    printf("%s",buf);
    // 关闭文件
    close(fd);
    return 0;
           }

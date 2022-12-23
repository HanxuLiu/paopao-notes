/*================================================================
*  Author: LiuHanxu
*  Date: 2022-12-23
*  Description: how to debug multi-process by gdb
================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0) { // 子进程
        printf("I am child, my pid = %d, my parent pid = %d\n", getpid(), getppid());
    } else if(pid > 0) { // 父进程
        printf("I am parent, my pid = %d, my child pid = %d\n", getpid(), pid);
        wait(NULL); // 等待子进程退出
    } else {
       perror("fork error!\n");
       return -1;
    }
    return 0;
}

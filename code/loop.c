/*================================================================
*  Author: LiuHanxu
*  Date: 2023-01-17
*  Description: 
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void loop(int flag)
{
  while(flag) {
    printf("loop .... (pid = %d)\n", getpid());
    sleep(3);
  }
}

int main()
{
  int flag = 1;
  loop(flag);
  return 0;
}

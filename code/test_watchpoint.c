/*================================================================
*  Author: LiuHanxu
*  Date: 2022-06-11
*  Description: 
================================================================*/
#include <stdio.h>

int main()
{
  int a = 1, b = 2, c = 3;
  printf("before: a = %d, b = %d, c = %d\n", a, b, c);
  int* ptr = &c;
  for(int i=0; i<=100; i++)
  {
    if (i == 66) 
      a = 0;
    if (i == 88) 
      b = 0;
    if (i == 99)
      *ptr = 123;
  }
  printf("after: a = %d, b = %d, c = %d\n", a, b, c);
  return 0;
}

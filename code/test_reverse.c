/*================================================================
*  Author: LiuHanxu
*  Date: 2022-12-25
*  Description: This test used for reverse debugging
================================================================*/
#include<stdio.h>

int fun(int n) {
  int sum = 0;
  for (int i=0; i<=n; i++)
    sum += i;
  return sum;
}

int main() {
  int x = 10, y = 0;
  y = fun(x);
  printf("y = %d\n", y);
  return 0;
}

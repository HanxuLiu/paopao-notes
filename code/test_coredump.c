/*================================================================
*  Author: LiuHanxu
*  Date: 2022-12-24
*  Description: 
================================================================*/
#include "stdio.h"
#include <stdlib.h>

void coredump()
{
    char *pStr = "test_coredump";
    printf("Next line will coredump.\n");
    free(pStr);
}

int main()
{
    coredump();
    return 0;
}

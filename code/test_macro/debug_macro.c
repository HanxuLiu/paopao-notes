/*================================================================
*  Author: liu-paopao
*  Date: 2023-07-14
*  Description: Demo for debug macro by 'gcc -E -P' and 'indent'
================================================================*/

#include<stdio.h>

#define ADD(name, max, p) \
void name(int *p) \
{ \
    for(int i = 0; i <= max; i++) { \
                *p = *p + i; \
    } \
    printf("0 + 1 + ... + %d = %d\n", max, *p); \
}

int main()
{
	int a = 0, b = 0;
	int *pa = &a;
	int *pb = &b;
	ADD(add_to_10, 10, pa)
	ADD(add_to_100, 100, pb)
	add_to_10(pa);
	add_to_100(pb);
	return 0;
}
